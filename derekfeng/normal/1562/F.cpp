#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fout fflush(stdout) 
int Tc,n,per[10004],ans[100003];
ll a[103][103];
bool flg[200004];
int tot,pri[200004];
bool used[103];
ll ask(int x,int y){ll ret;printf("? %d %d\n",x,y);fout;scanf("%lld",&ret);fout;return ret;}
void out(int n,int *a){printf("!");for(int i=1;i<=n;i++)printf(" %d",a[i]);puts("");fout;}
void init(int n=2e5){
	flg[1]=1;
	for(int i=1;i<=n;i++){
		if(!flg[i])pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<=n;j++){
			flg[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
}
int maxprime(ll x){for(int i=tot;;i--)if(x%pri[i]==0)return pri[i];}
vector<int>getfac(ll x){
	vector<int>ret;
	for(int i=1;i<=tot&&x>1;i++)
		while(x%pri[i]==0)ret.push_back(pri[i]),x/=pri[i];
	return ret;
}
void solve1(){
	for(int i=1;i<=n;i++)used[i]=0;
	ll mx=0;
	int I,J;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		a[i][j]=a[j][i]=ask(i,j);
		if(a[i][j]>mx)mx=a[i][j],I=i,J=j;
	}
	int R=ceil(sqrt(mx));
	int cur;
	bool RisI=1;
	for(int i=1;i<=n&&RisI;i++)if(i!=I&&a[I][i]%R!=0)RisI=0;
	if(RisI)cur=I;
	else cur=J;
	ans[cur]=R;used[cur]=1;
	for(int i=R,j=1;j<n;i--,j++){
		int ncur;
		ll mx=0;
		for(int j=1;j<=n;j++)if(!used[j]&&cur!=j&&a[cur][j]>mx)mx=a[cur][j],ncur=j;
		ans[ncur]=i-1,cur=ncur,used[cur]=1;
	}
	out(n,ans);
}
void solve2(){
	unsigned seed=chrono::system_clock::now().time_since_epoch().count();
	for(int i=1;i<=n;i++)per[i]=i;
	shuffle(per+1,per+n+1,default_random_engine(seed));
	ll mx=0;
	int I,J,notI;
	for(int i=1;i<=n;i+=2){
		ll tmp;
		if(i==n)tmp=ask(per[i-1],per[i]);
		else tmp=ask(per[i],per[i+1]);
		int gp=maxprime(tmp);
		if(gp>mx){
			mx=gp;
			if(i==n)I=per[i-1],J=per[i];
			else I=per[i],J=per[i+1];
		}else notI=per[i];
	}
	int maxP;
	if(ask(notI,I)%mx==0)maxP=I;
	else maxP=J;
	ans[maxP]=mx;
	for(int i=1;i<=n;i++)if(i!=maxP)ans[i]=ask(i,maxP)/mx;
	out(n,ans);
}
void solve3(){
	for(int i=1;i<=n;i++)ans[i]=0;
	mt19937 rng(19260817);
	for(int t=1;t<=4000;t++){
		int I=rng()%n+1,J=rng()%n+1;
		while(I==J)J=rng()%n+1;
		vector<int>fc=getfac(ask(I,J));
		if(fc.size()==2&&fc[0]>500&&fc[1]>500){
			bool first1=1;
			for(int i=0;i<100;i++){
				int K=rng()%n+1;
				while(K==I||K==J)K=rng()%n+1;
				if(ask(I,K)%fc[0]!=0){
					first1=0;
					break;
				}
			}
			int t1,t2,mx,pos;
			if(!first1)t1=fc[1],t2=fc[0];
			else t1=fc[0],t2=fc[1];
			ans[I]=t1,ans[J]=t2;
			for(int i=1;i<=n;i++){
				if(i==I||i==J)continue;
				ll u=ask(I,i);
				if(u/t1>500){
					ans[i]=u/t1;
					if(!flg[u/t1]){
						mx=u/t1;
						pos=i;
					}
				}
			}
			for(int i=1;i<=n;i++)if(ans[i]==0)
				ans[i]=ask(pos,i)/mx;
			break;
		}
	}
	out(n,ans);
}
void solve(){
	fout;
	scanf("%d",&n);
	fout;
	if(n<=100)solve1();
	else if(n<=10000)solve2();
	else solve3();
}
int main(){
	init();
	for(scanf("%d",&Tc);Tc--;solve());
}
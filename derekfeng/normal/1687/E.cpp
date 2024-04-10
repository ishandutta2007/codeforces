#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e6+5,M=1e5+5;
int n,mx,T,pri[N],tot;bool flg[N];
void init(){
	T=sqrt(mx);
	for(int i=2;i<=mx;i++){
		if(!flg[i])pri[++tot]=i;
		for(int j=1;j<=tot&&pri[j]*i<=mx;j++){
			flg[pri[j]*i]=1;
			if(i%pri[j]==0)break;
		}
	}
}
vector<pii>getpri(int x){
	vector<pii>res;
	for(int i=1;i<=tot&&x>1;i++){
		if(pri[i]*pri[i]>x)break;
		if(x%pri[i]==0){
			int cnt=0;
			while(x%pri[i]==0)++cnt,x/=pri[i];
			res.push_back({pri[i],cnt});
		}
	}
	if(x>1)res.push_back({x,1});
	return res;
}
int f[N],a[M],dfn[N];bool used[M];
void getg(vector<int>v){
	if(v.empty())return;
	int G=0;for(auto x:v)G=__gcd(G,a[x]);
	vector<pii>wg=getpri(G);memset(f,0,sizeof(f));
	for(auto [p,c]:wg)f[p]=c;vector<int>ans,rem,nrem;
	for(int i=1;i<=mx;i++)if(!flg[i])rem.push_back(i);
	for(auto x:v){
		vector<pii>w=getpri(a[x]);
		for(auto [p,c]:w)dfn[p]=c;
		bool ok=0;nrem.clear();
		for(auto y:rem){
			if(dfn[y]==f[y])ok=1;
			else nrem.push_back(y);
		}
		rem=nrem;if(ok)ans.push_back(x);
		for(auto [p,c]:w)dfn[p]=0;
	}
	int GG=0;
	for(int i=1;i<ans.size();i++)GG=__gcd(GG,a[ans[i]]);
	int it=GG==G;
	for(int i=it;i<ans.size();i++)used[ans[i]]=1;
}
vector<int>pos;
int main(){
	scanf("%d",&n);vector<int>v;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back(i),mx=max(mx,a[i]);
	init();getg(v);v.clear();
	for(int i=1;i<=n;i++)if(!used[i])v.push_back(i);getg(v);
	for(int i=1;i<=n;i++)if(used[i])pos.push_back(i);
	int t=pos.size();sort(pos.begin(),pos.end());
	vector<vector<int> >ans;
	int num=0;
	for(int i=1;i<(1<<t);i++){
		int z=__builtin_popcount(i);
		num+=abs(z-2);
	}
	printf("%d\n",num);
	for(int i=1;i<(1<<t);i++){
		int z=__builtin_popcount(i);
		int h=((z&1)?-1:1)*(z-2);
		if(h<0){
			int T=-h;
			while(T--){
				printf("%d %d ",1,z);
				for(int j=0;j<t;j++)
					if((i>>j)&1)printf("%d ",pos[j]);
				puts("");
			}
		}else{
			while(h--){
				printf("%d %d ",0,z);
				for(int j=0;j<t;j++)
					if((i>>j)&1)printf("%d ",pos[j]);
				puts("");
			}
		}
	}
}
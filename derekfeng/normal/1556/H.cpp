#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
#define fi first
#define se second
#define mkp make_pair
mt19937 ha(19260817);
piii edg[1300];
int n,K,d[55],a[55],final_ans=1e9,N;
int calc(){
	int sum=0;
	for(int i=1;i<=n;i++)sum+=max(0,a[i]-d[i]);
	return sum;
}
int f[55],ans;
bool used[1300];
int F(int x){
	return f[x]==x?x:f[x]=F(f[x]);
}
void sol(){
	for(int i=1;i<=n;i++)f[i]=i,a[i]=0;
	for(int i=1;i<=N;i++)used[i]=0;
	ans=0;
	int pt=0;
	for(int i=1;i<=N;i++){
		piii x=edg[i];
		int U=F(x.se.fi),V=F(x.se.se);
		if(U!=V){
			f[U]=V;
			ans+=x.fi;
			a[edg[i].se.fi]++,a[edg[i].se.se]++;
			used[i]=1;
			++pt;
		}
	}
	int q[100];memset(q,0,sizeof(q));
	for(int i=1;i<=N;i++)if(used[i])q[edg[i].se.fi]++,q[edg[i].se.se]++;
	int sum=0,ff=0;
	while(sum=calc()){
		int mx=0,id=0;
		while(!mx){
			for(int i=N;i;i--)if(used[i]){
				piii x=edg[i];
				int U=x.se.fi,V=x.se.se;
				if(d[U]<a[U]||d[V]<a[V])if(ha()%4){
					id=i,mx=x.fi;
					break;
				}
			}
		}
		int U=edg[id].se.fi,V=edg[id].se.se;
		a[U]--,a[V]--;
		used[id]=0;
		ans-=mx;
		for(int i=1;i<=n;i++)f[i]=i;
		for(int i=1;i<=N;i++)if(used[i])f[F(edg[i].se.fi)]=F(edg[i].se.se);
		mx=0;
		for(int i=1;i<=N;i++)if(!used[i]&&i!=id&&F(edg[i].se.fi)!=F(edg[i].se.se)){
			a[edg[i].se.fi]++,a[edg[i].se.se]++;
			mx=max(sum-calc(),mx);
			a[edg[i].se.fi]--,a[edg[i].se.se]--;
		}
		bool flg=0;
		while(!flg){
			for(int i=1;i<=N;i++)if(!used[i]&&i!=id&&F(edg[i].se.fi)!=F(edg[i].se.se)){
				piii x=edg[i];
				int U=x.se.fi,V=x.se.se;
				a[U]++,a[V]++;
				if(sum-calc()>0||!mx)if(ha()%4){
					used[i]=1,ans+=x.fi,flg=1;
					break;
				}
				if(ff)if(sum-calc()>=0)if(ha()%4==0){
					used[i]=1,ans+=x.fi,flg=1;
					break;
				}
				a[U]--,a[V]--;
			}
		}
		ff^=1;
	}
	final_ans=min(final_ans,ans);
}
int main(){
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++)d[i]=1e9;
	for(int i=1;i<=K;i++)scanf("%d",&d[i]);
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++){
		int w;scanf("%d",&w);
		edg[++N]=mkp(w,mkp(i,j));
	}
	sort(edg+1,edg+N+1);
	while((double)clock()/CLOCKS_PER_SEC<=2)sol();
	printf("%d",final_ans);
}
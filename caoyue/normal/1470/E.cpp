#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=1e5+7;
const int INF=1e9+7;
int T,n,c,q;
int p[N];
ll f[N][5],L[N][5],R[N][5],l[5],r[5];
int id[N][5];
bool cmp(int x,int y){return p[x]<p[y];}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&c,&q);
		rep(i,n)scanf("%d",&p[i]);
		rep(i,n+10)rep0(j,c+1)f[i][j]=0;
		rep0(i,c+1)f[n+1][i]=1;
		for(int i=n;i;i--){
			rep0(j,c+1){
				f[i][j]=f[i+1][j];
				rep(k,j){
					if(i+k>n)break;
					f[i][j]+=f[i+k+1][j-k];
				}
			}
		}
		rep(i,n){
			rep0(j,c+1)id[i][j]=i+j;
			sort(id[i],id[i]+c+1,cmp);
		}
		rep0(i,c+1){
			L[1][i]=1;
			R[1][i]=f[1][i];
			rep(j,n){
				ll k,vl=0,vr=0;
				for(k=0;id[j][k]!=j;k++)if(id[j][k]-j<=i)vl+=f[id[j][k]+1][i-id[j][k]+j];
				for(k++;k<=c;k++)if(id[j][k]-j<=i)vr+=f[id[j][k]+1][i-id[j][k]+j];
				L[j+1][i]=L[j][i]+vl;
				R[j+1][i]=R[j][i]-vr;
			}
		}
		while(q--){
			int x,cnt=0,w=1,o=c; ll v; scanf("%d%I64d",&x,&v);
			if(v>f[1][c]){
				puts("-1");
				continue;
			}
			while(1){
				if(L[n+1][o]-L[w][o]+1ll<=v&&v<=R[n+1][o]-L[w][o]+1ll)break;
				int a=w,b=n,g;
				while(a<b-1){
					int mid=(a+b)>>1;
					if(L[mid+1][o]-L[w][o]+1ll<=v&&v<=R[mid+1][o]-L[w][o]+1ll)a=mid;
					else b=mid;
				}
				if(L[a+1][o]-L[w][o]+1ll>v||v>R[a+1][o]-L[w][o]+1ll)g=a;
				else g=b;
				if(v<L[g+1][o]-L[w][o]+1){
					v-=(L[g][o]-L[w][o]);
					for(int k=0;id[g][k]!=g;k++){
						if(id[g][k]-g<=o){
							if(v>f[id[g][k]+1][o-id[g][k]+g])v-=f[id[g][k]+1][o-id[g][k]+g];
							else{
								w=id[g][k]+1;
								o=o-id[g][k]+g;
								l[cnt]=g;
								r[cnt++]=id[g][k];
								break;
							}
						}
					}
				}
				else{
					v-=(R[g+1][o]-L[w][o]+1);
					int k=0;
					for(;id[g][k]!=g;k++);
					for(k++;k<=c;k++){
						if(id[g][k]-g<=o){
							if(v>f[id[g][k]+1][o-id[g][k]+g])v-=f[id[g][k]+1][o-id[g][k]+g];
							else{
								w=id[g][k]+1;
								o=o-id[g][k]+g;
								l[cnt]=g;
								r[cnt++]=id[g][k];
								break;
							}
						}
					}
				}
			}
			int Ans=p[x];
			rep0(i,cnt)if(l[i]<=x&&r[i]>=x)Ans=p[l[i]+r[i]-x];
			printf("%d\n",Ans);
		}
	}
	return 0;
}
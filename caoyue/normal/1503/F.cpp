#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<vector>
#include<bitset>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=8e5+7;
const int INF=1e9+7;
int n,cnt=0,c1,c2;
int a[N],b[N],ad[N][2],bd[N][2],fr1[N],fr2[N],p[N];
vector<int>w[N];
bool vis[N];
void add(int x){
	if(x<=n*2)p[++cnt]=x;
	else for(int j=0;j<w[x].size();j++)add(w[x][j]);
}
int main(){
	scanf("%d",&n);
	rep(i,2*n){
		scanf("%d%d",&a[i],&b[i]);
		if(a[i]>0)ad[a[i]][0]=i;
		else ad[-a[i]][1]=i;
		if(b[i]>0)bd[b[i]][0]=i;
		else bd[-b[i]][1]=i;
	}
	rep(i,n){
		fr1[ad[i][0]]=ad[i][1];
		fr1[ad[i][1]]=ad[i][0];
		fr2[bd[i][0]]=bd[i][1];
		fr2[bd[i][1]]=bd[i][0];
	}
	int nw=2*n;
	rep(i,nw){
		if(((a[i]>0)^(b[i]>0))==0)continue;
		if(vis[i])continue;
		int t1=fr1[i],t2=fr2[i];
		if(t1==t2){
			puts("NO");
			return 0;
		}
		nw++;
		w[nw].clear();
		if(a[i]>0){
			w[nw].push_back(t2);
			w[nw].push_back(i);
			w[nw].push_back(t1);
		}
		else{
			w[nw].push_back(t1);
			w[nw].push_back(i);
			w[nw].push_back(t2);
		}
		a[nw]=a[t2];
		b[nw]=b[t1];
		fr1[nw]=fr1[t2];
		fr1[fr1[t2]]=nw;
		fr2[nw]=fr2[t1];
		fr2[fr2[t1]]=nw;
		vis[i]=vis[t1]=vis[t2]=1;
	}
	rep(i,nw){
		if(vis[i])continue;
		if(a[i]<0)continue;
		if(fr1[i]!=fr2[i]){
			puts("NO");
			return 0;
		}
		add(i);
		add(fr1[i]);
	}
	puts("YES");
	rep(i,cnt)printf("%d %d\n",a[p[i]],b[p[i]]);
	puts("");
	return 0;
}
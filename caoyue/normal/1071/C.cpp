#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstdio>
#include<time.h>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
const int N=227;
const int M=5e5+7;
const int INF=1e9+7;
int dis[M],p2[N],rr[N],fr[M],a[M];
queue<int>q;
struct op{int l,m,r;}p[M];
int n,vf,cm=0;
void work(int k,bool tt){
	vf=k;
	p2[0]=1;
	int cnt=0;
	rep(i,k)p2[i]=p2[i-1]<<1;
	rep(i,k){
		rep(j,k){
			if(i+j>k)continue;
			if(i-j<1&&tt)continue;
			int nw=p2[i-1]+p2[i+j-1];
			if(i-j)nw+=p2[i-j-1];
			rr[++cnt]=nw;
		}
	}
	memset(dis,120,sizeof(dis));
	dis[0]=0;
	q.push(0);
	while(!q.empty()){
		int t=q.front();
		q.pop();
		rep(j,cnt){
			if(dis[t^rr[j]]>dis[t]+1){
				dis[t^rr[j]]=dis[t]+1;
				fr[t^rr[j]]=t;
				q.push(t^rr[j]);
			}
		}
	}
}
int getb(int L,int R){
	int ans=0;
	for(int i=R;i>=L;i--)ans=(ans<<1)|a[i];
	return ans;
}
void pri(int x,int d){
	if(!x)return;
	int v=fr[x]^x,nw=0,h1,h2,h3;
	rep0(i,vf){
		if(v&p2[i]){
			nw++;
			if(nw==1)h1=i+1+d;
			if(nw==2)h2=i+1+d;
			if(nw==3)h3=i+1+d;
		}
	}
	if(nw==2)h3=h2,h2=h1,h1=h2*2-h3;
	p[++cm]=(op){h1,h2,h3};
	a[h1]^=1;
	a[h2]^=1;
	a[h3]^=1;
	pri(fr[x],d);
}

int main(){
	scanf("%d",&n);
	rep(i,n)scanf("%d",&a[i]);
	if(n<15){
		work(n,1);
		int v=getb(1,n);
		if(dis[v]>INF)printf("NO\n");
		else{
			pri(v,0);
			printf("YES\n");
			printf("%d\n",cm);
			rep(i,cm)printf("%d %d %d\n",p[i].l,p[i].m,p[i].r);
		}
	}
	else{
		work(15,0);
		int L,R;
		for(R=n,L=n-14;L>15;L-=15,R-=15){
			int q=getb(L,R);
			pri(q,L-1);
		}
		work(15,1);
		int q=getb(1,15);
		pri(q,0);
		int r=getb(L,L+14);
		pri(r,L-1);
		printf("YES\n");
		printf("%d\n",cm);
		rep(i,cm)printf("%d %d %d\n",p[i].l,p[i].m,p[i].r);
	}
	return 0;
}
//32 0 1 1 1 0 0 1 0 1 1 0 1 1 1 1 0 0 0 1 0 0 1 1 1 1 1 0 1 0 1 1 1
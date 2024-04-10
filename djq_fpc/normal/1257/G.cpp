#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<map>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define mod 998244353
using namespace std;
const int maxn=262144;
int n,m,i,j,w[maxn+5],inv[maxn+5],rev[maxn+5],a[maxn+5],b[maxn+5];
map<int,int> cnt;int seq[maxn+5],cs;
vector<int> ans[maxn+5];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq; 
int qp(int x,int y)
{
	int z=1;
	while(y){
		if(y&1) z=1ll*z*x%mod;
		x=1ll*x*x%mod;y/=2; 
	}
	return z;
}
int getrev(int x)
{
	int len=1;
	while(len<x)len=len+len;
	fz0k(i,len) rev[i]=rev[i/2]/2+((i&1)*(len>>1));
	return len;
}
void ntt(int *a,int len,int op)
{
	int i,j,k,ys,t;
	fz0k(i,len)if(rev[i]<i)swap(a[i],a[rev[i]]);
	for(i=1,ys=maxn/2;i<len;(i<<=1),ys=maxn/i/2)for(j=0;j<len;j+=i+i)for(k=0,t=(op==1?0:maxn);k<i;k++,t+=op*ys){
		int x=a[j+k],y=1ll*a[j+k+i]*w[t]%mod;a[j+k]=x+y;a[j+k+i]=x-y+mod;
		if(a[j+k]>=mod) a[j+k]-=mod;if(a[j+k+i]>=mod) a[j+k+i]-=mod;
	}
	if(op==-1)fz0k(i,len){
		a[i]=1ll*a[i]*inv[len]%mod;
	}
}
int main()
{
	inv[1]=1;
	w[0]=1;
	w[1]=qp(3,(mod-1)/maxn);
	fz(i,2,maxn){
		w[i]=1ll*w[i-1]*w[1]%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	scanf("%d",&n);
	fz1(i,n){
		int x;
		scanf("%d",&x);
		cnt[x]++;
	}
	ff(cnt,it){
		seq[++cs]=it->second;
		pq.push(make_pair(seq[cs]+1,cs));
		fz0g(j,seq[cs]) ans[cs].push_back(1);
	}
	fz1(j,cs-1){
		int x=pq.top().second;pq.pop();
		int y=pq.top().second;pq.pop();
		int len=getrev(ans[x].size()+ans[y].size());
		fz0k(i,len){
			a[i]=b[i]=0;
			if(i<ans[x].size()) a[i]=ans[x][i];
			if(i<ans[y].size()) b[i]=ans[y][i];
		}
		ntt(a,len,1);ntt(b,len,1);
		fz0k(i,len) a[i]=1ll*a[i]*b[i]%mod;
		ntt(a,len,-1);
		ans[x].clear();ans[y].clear();
		fz0k(i,len) ans[x].push_back(a[i]);
		while(!ans[x].empty()&&ans[x].back()==0) ans[x].pop_back();
		pq.push(make_pair(ans[x].size(),x));
	}
	cout<<ans[pq.top().second][n/2]<<endl;
	return 0;
}
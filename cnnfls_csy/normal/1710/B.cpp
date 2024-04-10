#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<ctime>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<bitset>
#include<cassert>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(((long long)(n))-1);(i)>=0;(i)--)
#define fz(i,x,y) for ((i)=(x);(i)<=(y);(i)++)
#define fd(i,y,x) for ((i)=(y);(i)>=(x);(i)--)
#define fzin fz1(i,n)
#define fzim fz1(i,m)
#define fzjn fz1(j,n)
#define fzjm fz1(j,m)
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
#define pb push_back
#define mk make_pair
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#ifndef ONLINE_JUDGE
	FILE *___=freopen("1.in","r",stdin);
#endif
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
bool _1;
int t,n,m,len,a[200005],i,j,px[200005],py[200005],lg[600005];
long long s0[600005],s1[600005];
long long /*f[21][600005],*/g[21][600005],h[21][600005];
long long pre[600005],suf[600005];
vector<int> all;
bool _2;
/*long long queryf(int l,int r)
{
	int t=lg[r-l+1];
	return max(f[t][l],f[t][r-(1<<t)+1]);
}*/
long long queryg(int l,int r)
{
	int t=lg[r-l+1];
	return max(g[t][l],g[t][r-(1<<t)+1]);
}
long long queryh(int l,int r)
{
	int t=lg[r-l+1];
	return max(h[t][l],h[t][r-(1<<t)+1]);
}
void solve()
{
	read(n);read(m);all.clear();
	fz1(i,n){
		read(px[i]);read(py[i]);
		all.push_back(px[i]);
		all.push_back(px[i]-py[i]);
		all.push_back(px[i]+py[i]);
	}
	sort(all.begin(),all.end());all.resize(unique(all.begin(),all.end())-all.begin());
	fz1(i,n){
		int x=upper_bound(all.begin(),all.end(),px[i])-all.begin();
		int l=upper_bound(all.begin(),all.end(),px[i]-py[i])-all.begin();
		int r=upper_bound(all.begin(),all.end(),px[i]+py[i])-all.begin();
		s1[l]++;s1[x]--;s0[l]-=px[i]-py[i];s0[x]+=px[i]-py[i];
		s1[x]--;s1[r]++;s0[x]+=px[i]+py[i];s0[r]-=px[i]+py[i];
	}
	fz1(i,all.size()){
		s0[i]+=s0[i-1];
		s1[i]+=s1[i-1];
	}
	len=all.size()-1;assert(s0[len+1]==0&&s1[len+1]==0);
	fz1(i,len){
//		f[0][i]=max(s0[i]+s1[i]*all[i-1],s0[i]+s1[i]*all[i]);
		g[0][i]=max(s0[i]+(s1[i]+1)*all[i-1],s0[i]+(s1[i]+1)*all[i]);
		h[0][i]=max(s0[i]+(s1[i]-1)*all[i-1],s0[i]+(s1[i]-1)*all[i]);
	}
	pre[0]=suf[len+1]=0;
	fz1(i,len) pre[i]=max(pre[i-1],max(s0[i]+s1[i]*all[i-1],s0[i]+s1[i]*all[i]));
	fd1(i,len) suf[i]=max(suf[i+1],max(s0[i]+s1[i]*all[i-1],s0[i]+s1[i]*all[i]));
	fz1(j,20)fz1(i,len-(1<<j)+1){
//		f[j][i]=max(f[j-1][i],f[j-1][i+(1<<j-1)]);
		g[j][i]=max(g[j-1][i],g[j-1][i+(1<<j-1)]);
		h[j][i]=max(h[j-1][i],h[j-1][i+(1<<j-1)]);
	}
	fz1(i,n){
		int x=upper_bound(all.begin(),all.end(),px[i])-all.begin();
		int l=upper_bound(all.begin(),all.end(),px[i]-py[i])-all.begin();
		int r=upper_bound(all.begin(),all.end(),px[i]+py[i])-all.begin();
		if(1<l){
			if(pre[l-1]>m){putchar('0');continue;}
		}
		if(r<=len){
			if(suf[r]>m){putchar('0');continue;}
		}
		if(queryh(l,x-1)+(px[i]-py[i])>m){putchar('0');continue;}
		if(queryg(x,r-1)-(px[i]+py[i])>m){putchar('0');continue;}
		putchar('1');
	}
	puts("");
	fz1(i,len) s0[i]=s1[i]=0;
}
int main()
{
//	cerr<<(&_2-&_1)/1048576<<endl;
	fz(i,2,600002) lg[i]=lg[i/2]+1;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}
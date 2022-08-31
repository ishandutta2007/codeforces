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
int n,m,i,j;
int f[500005];
int vis[17];
string st;
void solve()
{
	read(n);st.clear();
	int cr=0,cb=0;
	fz1(i,n){
		char c;while(!isupper(c=getchar()));
		st.push_back(c);
		cr+=(c=='R');
		cb+=(c=='B');
	}
	if(cr>cb){puts("Alice");return;}
	if(cr<cb){puts("Bob");return;}
	int lst=1,xorsum=0;
	fz(i,1,n-1){
		if(st[i]!=st[i-1]) lst++;
		else xorsum^=f[lst],lst=1;
	}
	xorsum^=f[lst];
	if(xorsum) puts("Alice"); else puts("Bob");
}
bitset<500005> bs[16],rs[16];
int main()
{
//	freopen("1.txt","w",stderr);
	f[0]=f[1]=0;
	int mx=0;
	fz(i,2,500000){
		fz0g(j,min(1000,i-2)) vis[f[j]^f[i-2-j]]=1;
		while(vis[f[i]]) f[i]++;
		memset(vis,0,sizeof(vis));
		mx=max(mx,f[i]);
//		cerr<<i<<' '<<f[i]<<endl;
	}
/*	bs[0].set(0);bs[0].set(1);
	rs[0].set(500000);rs[0].set(499999);
	int mx=0;
	fz(i,2,500000){
		for(;;){
			bool flg=0;
			fz0g(j,mx)if((f[i]^j)>=j){
				if((bs[j]&(rs[f[i]^j]>>(500000-i+2))).count()){
					flg=1;break;
				}
			}
			if(!flg) break;f[i]++;
		}
		bs[f[i]].set(i);rs[f[i]].set(500000-i);
		mx=max(mx,f[i]);
//		cerr<<i<<' '<<f[i]<<' '<<mx<<endl;
	}*/
	int t;read(t);
	while(t--){
		solve();
	}
	return 0;
}
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
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);(i)++)
#define fd1(i,n) for ((i)=(n);(i)>=1;(i)--)
#define fz0g(i,n) for ((i)=0;(i)<=(n);(i)++)
#define fd0g(i,n) for ((i)=(n);(i)>=0;(i)--)
#define fz0k(i,n) for ((i)=0;(i)<(n);(i)++)
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;(i)--)
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
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
#define int long long
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,a[100005],b[7],lst[100005];
multiset<int> s;
struct ii
{
	int id,x;
};
bool cmp(ii x,ii y)
{
	return x.x<y.x;
}
vector<ii> v;
int f(int x,int y)
{
	return a[x]-b[y];
}
signed main()
{
	fz1(i,6)read(b[i]);
	sort(b+1,b+6+1);
	reverse(b+1,b+6+1);
	read(n);
	fz1(i,n)read(a[i]);
//	sort(a+1,a+n+1);
	fz1(i,n){
		s.insert(f(i,1));
		lst[i]=1;
		fz(j,1,5){
			v.push_back((ii){i,f(i,j)});
		}
	}
	sort(v.begin(),v.end(),cmp);
	int ans=*s.rbegin()-*s.begin();
	ff(v,it){
		int t=it->id;
		s.erase(s.find(f(t,lst[t])));
		s.insert(f(t,++lst[t]));
		ans=min(ans,*s.rbegin()-*s.begin()); 
	}
	cout<<ans<<endl;
	return 0;
}
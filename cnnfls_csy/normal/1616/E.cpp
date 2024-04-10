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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int tt,n,m,i,j,c[100005];
string s,t;
long long l,r,mid,ans;
vector<int> pos[26];int pt[26];
int query(int x){int s=0;while(x)s+=c[x],x-=(x&-x);return s;}
void add(int x,int y){while(x<=n)c[x]+=y,x+=(x&-x);}
bool check(long long x)
{
	string res;int i;fz1(i,n)c[i]=0;fz0k(i,26) pt[i]=0;
//	cerr<<x<<' ';
	fz1(i,n){
		fz0k(j,26){
			if(pt[j]<pos[j].size()&&pos[j][pt[j]]-query(pos[j][pt[j]])-1<=x){
				res.push_back(j+'a');
				x-=pos[j][pt[j]]-query(pos[j][pt[j]])-1;
				add(pos[j][pt[j]],1);
				pt[j]++;
				break;
			}
		}
	}
//	cerr<<res<<endl;
	return res<t;
}
void solve()
{
	cin>>n>>s>>t;s=" "+s;
	fz0k(i,26) pos[i].clear();fz1(i,n) pos[s[i]-'a'].push_back(i);
	l=-1;r=1ll*n*n;ans=-1;
	while(l<r){
		mid=(l+r+1)/2;
		if(check(mid)) ans=mid,r=mid-1;
		else l=mid;
	}
	printf("%lld\n",ans);
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>tt;
	while(tt--){
		solve();
	}
	return 0;
}
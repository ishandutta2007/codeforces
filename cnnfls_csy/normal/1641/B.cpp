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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int t,n,m,i,j,k;
vector<pair<int,int> > ans;
basic_string<int> res,a;
void solve()
{
	ans.clear();res.clear();a.clear();
	read(n);a.resize(n);
	fz0k(i,n) read(a[i]);
	for(i=n-1;i>=0;i--){
		j=i-1;while(j>=0&&a[j]!=a[i])j--;
		if(j==-1){puts("-1");return;}
		basic_string<int> tmp=a.substr(j+1,i-j-1);
		fd0k(k,tmp.size()) ans.push_back(make_pair(j+tmp.size()-k-1,tmp[k]));
		a.erase(j);reverse(tmp.begin(),tmp.end());a=a+tmp;i=a.size();
		res.push_back(tmp.size()*2+2);
	}
	printf("%d\n",ans.size());
	ff(ans,it) printf("%d %d\n",it->first,it->second);
	printf("%d\n",res.size());
	reverse(res.begin(),res.end());
	ff(res,it) printf("%d ",*it);
	puts("");
}
int main()
{
	read(t);while(t--)solve();
	return 0;
}
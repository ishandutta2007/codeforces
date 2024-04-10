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
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define incm(x,y) {x=((x)+(y))%mod;}
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
#define fi first
#define se second
#define mk make_pair
using namespace std;
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,t;
string st,s1,s2;
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>st;
		st=st;s1=s2="";
		int cnt=0;
		fz0k(i,n){
			cnt+=(st[i]=='1');
		}
		if(cnt&1){
			puts("NO");
			continue;
		}
		cnt/=2; 
		int dep=0,t=0;
		fz0k(i,n){
			if(st[i]=='1'){
				if(--cnt>=0){
					s1.push_back('(');
					s2.push_back('(');
					dep++;
				}
				else{
					s1.push_back(')');
					s2.push_back(')');
					dep--;
				}
			}
			else{
				if(t^=1){
					s1.push_back(')');
					s2.push_back('(');
					dep--;
				}
				else{
					s1.push_back('(');
					s2.push_back(')');
					dep++;
				}
			}
			if(dep<0){
				puts("NO");
				break;
			}
		}
		if(i==n){
			puts("YES");
			puts(s1.c_str());
			puts(s2.c_str());
		}
	}
	return 0;
}
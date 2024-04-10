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
#define spln(i,n) (i==n?'\n':' ')
#define fac_init(n){fac[0]=fac[1]=inv[1]=fi[0]=fi[1]=1;fz(i,2,n){fac[i]=1ll*fac[i-1]*i%mod;inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;fi[i]=1ll*fi[i-1]*inv[i]%mod;}}
using namespace std;
int n,m,i,j,k,ans;
int a[405][405],s[405][405];
int f[405],g[405];
void solve()
{
	memset(a,0,sizeof(a));
	ans=0x3f3f3f3f;
	cin>>n>>m;
	fz1(i,n){
		fz1(j,m){
			char c;
			cin>>c;
			a[i][j]=(c-'0');
		}
	}
	fz1(i,n){
		fz1(j,m){
			s[i][j]=s[i-1][j]+a[i][j];
		}
	}
	fz1(i,n){
		fz(j,i+4,n){
			fz1(k,m){
				f[k]=s[j-1][k]-s[i][k]+!a[i][k]+!a[j][k];
				g[k]=(j-i-1)-(s[j-1][k]-s[i][k]);
				f[k]+=f[k-1];
			}
			int ss=0x3f3f3f3f;
			fz1(k,m){
				if(k-3>=1){
					ss=min(ss,g[k-3]-f[k-3]);
				}
				ans=min(ans,ss+f[k-1]+g[k]);
			} 
		}
	}
	cout<<ans<<endl;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
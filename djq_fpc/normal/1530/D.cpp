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
inline void read(int &x)
{
	char c;int f=1;
	while(!isdigit(c=getchar()))if(c=='-')f=-1;
	x=(c&15);while(isdigit(c=getchar()))x=(x<<1)+(x<<3)+(c&15);
	x*=f;
}
int n,m,i,j,t,a[200005],b[200005],c[200005];
vector<int> ed,bg,gl;
int main()
{
	read(t);
	while(t--){
		read(n);fz1(i,n)b[i]=c[i]=0;
		fz1(i,n) read(a[i]);
		fz1(i,n){
			if(!b[a[i]]){
				b[a[i]]=i;
				c[i]=a[i];
			}
		}
		ed.clear();bg.clear();gl.clear();
		fz1(i,n)if(!b[i]&&c[i]) ed.push_back(i);
		fz1(i,n)if(!c[i]){
			if(!b[i]) gl.push_back(i);
			else bg.push_back(i); 
		}
		if(gl.size()==1&&bg.empty()){
			i=a[gl[0]];
			c[gl[0]]=i;c[b[i]]=gl[0];
		}
		else if(gl.size()==1){
			ed.push_back(gl[0]);
			ff(gl,it){
				for(i=0;i<ed.size();i++)if(ed[i]!=*it)break;
				c[*it]=ed[i];swap(ed[i],ed.back());ed.pop_back();
			}
			ff(bg,it){
				c[*it]=ed.back();ed.pop_back();
			}
		}
		else{
			fz0k(i,gl.size()){
				c[gl[i]]=gl[(i+1)%gl.size()];
			}
			ff(bg,it){
				c[*it]=ed.back();ed.pop_back();
			}
		}
		int s=0;
		fz1(i,n) s+=(a[i]==c[i]);
		printf("%d\n",s);
		fz1(i,n)printf("%d%c",c[i],spln(i,n));
	}
	return 0;
}
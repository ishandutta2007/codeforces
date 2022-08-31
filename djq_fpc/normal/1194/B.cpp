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
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
int n,m,i,j,t,a[400005],cx[400005],cy[400005];
int id(int x,int y)
{
	return (x-1)*m+y;
}
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		fz1(i,n)cx[i]=0;fz1(i,m)cy[i]=0;
		fz1(i,n){
			scanf(" ");
			fz1(j,m){
				char c;
				scanf("%c",&c);
				if(c=='*'){
					a[id(i,j)]=1;
					cx[i]++;cy[j]++;
				}
				else{
					a[id(i,j)]=0;
				}
			}
		}
		int ans=n*m;
		fz1(i,n)fz1(j,m){
			ans=min(ans,(n+m-1)-(cx[i]+cy[j]-a[id(i,j)]));
		}
		printf("%d\n",ans);
	}
	return 0;
}
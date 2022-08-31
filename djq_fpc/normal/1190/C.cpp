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
#define rdst(st,len){static char ss[len];scanf(" %st",ss);(st)=ss;}
#define inc(x,y) {x+=(y);if(x>=mod)x-=mod;}
#define dec(x,y) {x-=(y);if(x<0)x+=mod;}
using namespace std;
string st;
int n,m,i,j,f[100005],s0[100005],s1[100005];
bool check(char c)
{
	int ans=0,i;
	for(i=1;st[i]==c;i++)ans++;
	for(i=n;st[i]==c;i--)ans++;
	return ans+m>=n;
}
int main()
{
	scanf("%d%d",&n,&m);
	rdst(st,100005);st=" "+st;
	fz1(i,n){
		f[i]=1;
		if(i>1&&st[i]==st[i-1])f[i]+=f[i-1];
		s0[i]=s0[i-1];s1[i]=s1[i-1];
		if(st[i]=='0')s0[i]++;else s1[i]++;
	}
	if(f[n]==n){
		puts("tokitsukaze");
		return 0;
	}
	if(check('0')||check('1')){
		puts("tokitsukaze");
		return 0;
	}
	fz1(i,n){
		if(f[i]>=m){
			puts("once again");
			return 0;
		}
	}
	fz1(i,n-m+1){
		if(s0[i-1]&&(s0[n]-s0[i+m-1])){
			puts("once again");
			return 0;
		}
		if(s1[i-1]&&(s1[n]-s1[i+m-1])){
			puts("once again");
			return 0;
		}
	}
	puts("quailty");
	return 0;
}
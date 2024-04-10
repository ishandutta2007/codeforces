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
long long n,m,i,j,s,a[100005];
int main()
{
	scanf("%I64d",&n);
	fz1(i,n){
		scanf("%I64d",&a[i]);
	}	
	sort(a+1,a+n+1);
	if((n>=2&&a[2]==0)||a[n]==0){
		puts("cslnb");
		return 0;
	}
	int cnt=0;
	fz(i,2,n){
		if(a[i]==a[i-1]){
			if(i>=3&&a[i-1]==a[i-2]+1){
				puts("cslnb");
				return 0;
			}
			cnt++;
		}
	}
	if(cnt>=2){
		puts("cslnb");
		return 0;
	}
	fz1(i,n){
		s+=(a[i]-(i-1));
	}
	if(s&1){
		puts("sjfnb");	
	}
	else{
		puts("cslnb");
	}
	return 0;
}
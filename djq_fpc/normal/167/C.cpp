#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<set>
#include<queue>
#define sqr(x) ((x)*(x))
#define fz1(i,n) for ((i)=1;(i)<=(n);++(i))
#define fd1(i,n) for ((i)=(n);(i)>=1;--(i))
#define fz0g(i,n) for ((i)=0;(i)<=(n);++(i))
#define fd0g(i,n) for ((i)=(n);(i)>=0;--(i))
#define fz0k(i,n) for ((i)=0;(i)<(n);++(i))
#define fd0k(i,n) for ((i)=(long long)((n)-1);(i)>=0;--(i))
#define fz(i,x,y) for ((i)=(x);(i)<=(y);++(i))
#define fd(i,y,x) for ((i)=(y);(i)>=(x);--(i))
#define ff(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rdst(st,len){static char ss[len];scanf(" %s",ss);(st)=ss;}
using namespace std;
long long n,m,t;
char g(long long n,long long m)
{
	if(m%2==1)return !(n&1);
	return !((n%(m+1))&1);
}
char f(long long n,long long m)
{
	if(n<m)swap(n,m);
	if(!m)return 0;
	char t=f(m,n%m);
	if(!t)return 1;
	return g((n-n%m)/m,m);
}
int main()
{
	scanf("%I64d",&t);
	while(t--){
		scanf("%I64d%I64d",&n,&m);
		if(f(n,m))puts("First");else puts("Second"); 
	}
	return 0;
}
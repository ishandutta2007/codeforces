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
int t,n,m,i,j,a[405],s[250005],f[250005],c[250005],r[250005],ord[250005];
long long ans=-1;
bool check(int id,long long x)
{
	x/=c[id];
	int remr=r[id],i;
	long long remo=x;
	fz(i,s[id],f[id]-1){
		if(a[i]+remo>=a[i+1]){
			remo-=a[i+1]-a[i];
		}
		else{
			if(!remr) return 0;
			remr--;remo=x;
			if(a[i]+remo>=a[i+1]){
				remo-=a[i+1]-a[i];
			}
			else return 0;
		}
	}
	return 1;
}
long long solve(int x)
{
	long long l=ans,r=0x3f3f3f3f3f3f3f3fll,mid;
	long long res;
	while(l<r){
		mid=(l+r+1)>>1;
		if(check(x,mid)){
			r=mid-1;
			res=mid;
		}
		else l=mid;
	}
	return res;
}
int main()
{
	srand(time(NULL));
	scanf("%d%d",&n,&m);
	fz1(i,n){
		scanf("%d",&a[i]);
	}
	fz1(i,m){
		ord[i]=i;
		scanf("%d%d%d%d",&s[i],&f[i],&c[i],&r[i]);
	}
	fz1(i,m){
		swap(ord[i],ord[(rand()*32768+rand())%m+1]);
	}
	fz1(i,m){
		if(ans==-1||!check(ord[i],ans)){
			ans=solve(ord[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
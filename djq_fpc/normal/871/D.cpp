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
long long ans;
int n,m,i,j,p[10000005],md[10000005],np[10000005],pc,cmd[10000005],smd[10000005],mu[10000005],cnt[10000005];
long long solve1()
{
	return 1ll*cnt[n]*(cnt[n]-1)/2;
}
long long solve2()
{
	long long ans=0;
	int i;
	fz1(i,n){
		if(i!=1) ans+=1ll*mu[i]*(n/i)*(n/i-1); else ans+=1ll*mu[i]*(cnt[n])*(cnt[n]-1);
	}
	return ans/2;
}
long long solve3()
{
	long long ans=0;
	int i,j=n;
	fz1(i,n){
		while(1ll*i*j>n) j--;
		ans+=1ll*cmd[i]*(smd[n]-smd[j]);
		if(i!=1&&1ll*md[i]*2<=n&&1ll*md[i]*md[i]>n) ans--;
	}
	return ans/2;
}
signed main()
{
	scanf("%lld",&n);
	mu[1]=1;md[1]=n+1;
	fz(i,2,n){
		if(!np[i]){
			p[++pc]=i;
			md[i]=i;
			mu[i]=-1;
		}
		fz1(j,pc){
			if(i*p[j]>n) break;
			np[i*p[j]]=1;
			md[i*p[j]]=p[j];
			mu[i*p[j]]=-mu[i];
			if(i%p[j]==0){
				mu[i*p[j]]=0;
				break;
			}
		}
	}
	fz1(i,n){
		if(md[i]*2<=n){
			cnt[i]++;
			cmd[md[i]]++;
		}
	}
	fz1(i,n){
		cnt[i]+=cnt[i-1];
		smd[i]=cmd[i]+smd[i-1];
	}
	cout<<solve1()+solve2()+solve3()<<endl;
	return 0;
}
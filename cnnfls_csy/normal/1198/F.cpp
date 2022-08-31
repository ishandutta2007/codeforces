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
int n,m,i,j,a[100005],np[100005],typ[100005],iit;
map<int,int> lst;
vector<int> to_rand,p;
void init()
{
	int i;
	for(i=2;i<=100000;i++){
		if(!np[i]){
			p.push_back(i);
			for(j=i+i;j<=100000;j+=i){
				np[j]=1;
			}
		}
	}
}
int f(int x)
{
	int i,s=1;
	for(i=0;i<p.size()&&p[i]*p[i]<=x;i++){
		if(x%p[i]==0){
			s*=p[i];
			while(x%p[i]==0)x/=p[i]; 
		}
	}
	return s*x;
}
void solve()
{
	int t1=iit,t2=iit;
	ff(to_rand,it){
		int x=*it;
		int nxt1=__gcd(t1,a[x]);
		int nxt2=__gcd(t2,a[x]);
		if(nxt1==t1){
			typ[x]=2;
			t2=nxt2;
			continue;
		}
		if(nxt2==t2){
			typ[x]=1;
			t1=nxt1;
			continue;
		}
		if(rand()&1){
			typ[x]=1;
			t1=nxt1;
		}
		else{
			typ[x]=2;
			t2=nxt2;
		}
	}
	if(t1==1&&t2==1){
		puts("YES");
		fz1(i,n){
			printf("%d ",typ[i]);
		}
		exit(0);
	} 
}
int main()
{
	double start=clock();
	srand(32187654);
	scanf("%d",&n);
	fz1(i,n){
		scanf("%d",&a[i]);
		a[i]=f(a[i]);
		if(lst.count(a[i])){
			typ[lst[a[i]]]=1;
			typ[i]=2;
			iit=__gcd(iit,a[i]);
		}
		else{
			lst[a[i]]=i;
		}
	}
	fz1(i,n){
		if(!typ[i]){
			to_rand.push_back(i); 
		}
	}
	while((clock()-start)/CLOCKS_PER_SEC<0.42){
		solve();
	}
	puts("NO");
	return 0;
}
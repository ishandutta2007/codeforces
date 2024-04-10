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
int n,q,i,j,md[1000005],fa[1000005],p[1000005],pc,a[150005],bel[150005];
set<pair<int,int> > s;
int fnd(int x)
{
	if(fa[x]==x)return x;
	return fa[x]=fnd(fa[x]);
}
vector<int> fjzys(int x)
{
	vector<int> s;
	while(x!=1){
		int t=md[x];
		s.push_back(md[x]);
		while(x%p[t]==0)x/=p[t];
	}
	return s;
}
int main()
{
	fz(i,2,1000002){
		if(!md[i]){
			p[++pc]=i;
			md[i]=pc;
		}
		fz1(j,pc){
			if(i*p[j]>1000002)break;
			md[i*p[j]]=j;
			if(i%p[j]==0)break;
		}
	}
	fz1(i,pc)fa[i]=i;
	read(n); read(q); 
	fz1(i,n){
		read(a[i]);
		vector<int> v=fjzys(a[i]);
		fz1(j,v.size()-1) fa[fnd(v[j])]=fnd(v[0]);
		bel[i]=v[0];
	}
	fz1(i,n) bel[i]=fnd(bel[i]);
	fz1(i,n){
		vector<int> v=fjzys(a[i]+1);
		ff(v,it){
			int x=fnd(*it),y=bel[i];
			if(x!=y) s.insert(make_pair(min(x,y),max(x,y)));
		}
		int j,k;
		for(j=0;j<v.size();j++){
			for(k=j+1;k<v.size();k++){
				int x=fnd(v[j]),y=fnd(v[k]);
				if(x!=y) s.insert(make_pair(min(x,y),max(x,y)));
			}
		}
	}
	while(q--){
		int x,y;
		read(x);read(y);
		x=bel[x];y=bel[y];
		if(x==y)puts("0");
		else if(s.count(make_pair(min(x,y),max(x,y)))) puts("1");
		else puts("2"); 
	}
	return 0;
}
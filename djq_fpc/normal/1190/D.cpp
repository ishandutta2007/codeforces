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
long long n,m,i,j,px[200005],py[200005],vis[200005],ans,cnt;
vector<long long> allx,ally,f[200005];
struct bit
{
	long long arr[200005];
	long long lowbit(int x) {return x&(-x);}
	void add(long long x,long long y)
	{
		if(vis[x])return;vis[x]=1;
		for (long long i=x;i<=ally.size();i+=lowbit(i)) arr[i]+=y;
	}
	long long query(long long x)
	{
		long long s=0;
		for (long long i=x;i>0;i-=lowbit(i)) s+=arr[i];
		return s;
	}
}s;
long long calc2(long long l,long long r)
{
	long long cnt=s.query(r)-s.query(l-1);
	return cnt*(cnt+1)/2;
}
long long calc(vector<long long> v)
{
	cnt=s.query(ally.size());
	v.insert(v.begin(),0);v.push_back(ally.size()+1);
	long long ans=cnt*(cnt+1)/2,i;
	for(i=1;i<v.size();i++){
		ans-=calc2(v[i-1]+1,v[i]-1);
	}
	return ans;
}
int main()
{
	scanf("%I64d",&n);
	fz1(i,n){
		scanf("%I64d%I64d",&py[i],&px[i]);
		px[i]*=-1;
		allx.push_back(px[i]);
		ally.push_back(py[i]);
	}
	sort(allx.begin(),allx.end());
	allx.resize(unique(allx.begin(),allx.end())-allx.begin());
	sort(ally.begin(),ally.end());
	ally.resize(unique(ally.begin(),ally.end())-ally.begin());
	fz1(i,n){
		px[i]=upper_bound(allx.begin(),allx.end(),px[i])-allx.begin();
		py[i]=upper_bound(ally.begin(),ally.end(),py[i])-ally.begin();
		f[px[i]].push_back(py[i]);
	}
	fz1(i,allx.size()){
		ff(f[i],it){
			s.add(*it,1);
		}sort(f[i].begin(),f[i].end());
		ans+=calc(f[i]);
	}
	cout<<ans<<endl;
	return 0;
}
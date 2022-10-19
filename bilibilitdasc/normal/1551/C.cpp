#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1;i<=(n);++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a);i<=(b);++i)
#define perk(i,a,b) for(int i=(a);i>=(b);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n;
char s[400005];
int cnt[5][200005];
int sc[200005];
int p[200005];
template<int a>
inline int counts(int i)
{
	return (cnt[a][i]<<1)-sc[i];
}
template<int a>
bool cmp(int i,int j)
{
	int ai=counts<a>(i);
	int aj=counts<a>(j);
	if(ai!=aj) return ai<aj;
	return i<j;
}
int sums;
int res;
int ans;
void Q()
{
	scanf("%d",&n);
	rep(i,n)
	{
		cnt[0][i]=cnt[1][i]=cnt[2][i]=cnt[3][i]=cnt[4][i]=sc[i]=0;
	}
	rep(i,n)
	{
		scanf("%s",s);
		for(int j=0,l=strlen(s);j<l;++j)
		{
			++cnt[s[j]-'a'][i];
			++sc[i];
		}
	}
	ans=0;
	for(int i=0;i<n;++i) p[i]=i;
	sort(p,p+n,cmp<0>);res=sums=0;
	for(int i=0;i<n;++i) sums+=counts<0>(i);
	if(sums>0) res=n;
	else
	for(int i=0;i<n;++i)
	{
		sums-=counts<0>(p[i]);
		if(sums>0)
		{
			res=n-i-1;
			break;
		}
	}
	ans=max(ans,res);
	sort(p,p+n,cmp<1>);res=sums=0;
	for(int i=0;i<n;++i) sums+=counts<1>(i);
	if(sums>0) res=n;
	else
	for(int i=0;i<n;++i)
	{
		sums-=counts<1>(p[i]);
		if(sums>0)
		{
			res=n-i-1;
			break;
		}
	}
	ans=max(ans,res);
	sort(p,p+n,cmp<2>);res=sums=0;
	for(int i=0;i<n;++i) sums+=counts<2>(i);
	if(sums>0) res=n;
	else
	for(int i=0;i<n;++i)
	{
		sums-=counts<2>(p[i]);
		if(sums>0)
		{
			res=n-i-1;
			break;
		}
	}
	ans=max(ans,res);
	sort(p,p+n,cmp<3>);res=sums=0;
	for(int i=0;i<n;++i) sums+=counts<3>(i);
	if(sums>0) res=n;
	else
	for(int i=0;i<n;++i)
	{
		sums-=counts<3>(p[i]);
		if(sums>0)
		{
			res=n-i-1;
			break;
		}
	}
	ans=max(ans,res);
	sort(p,p+n,cmp<4>);res=sums=0;
	for(int i=0;i<n;++i) sums+=counts<4>(i);
	if(sums>0) res=n;
	else
	for(int i=0;i<n;++i)
	{
		sums-=counts<4>(p[i]);
		if(sums>0)
		{
			res=n-i-1;
			break;
		}
	}
	ans=max(ans,res);
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	Q();
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/
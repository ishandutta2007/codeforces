#define LOCAL_TEST_MYSELF_FOR_FELIX_QIU_JIA_MING
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
int n,m,x,y,d;
int p[200005];
void in_sert(int i)
{
	p[i]=i;
}
int get_p_arent(int i)
{
	if(p[i]==i)
	return i;
	return p[i]=get_p_arent(p[i]);
}
void conn_ect(int i,int j)
{
	p[get_p_arent(i)]=get_p_arent(j);
}
bool is_in_1(int i,int j)
{
	return get_p_arent(i)==get_p_arent(j);
}
const int N=100000;
int res,ans=1;
int main()
{
	#ifndef LOCAL_TEST_MYSELF_FOR_FELIX_QIU_JIA_MING
	freopen("album.in","r",stdin);
	freopen("album.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	rep1(i,n)
	{
		in_sert(i);
		in_sert(i+N);
	}
	rep(i,m)
	{
		scanf("%d%d%d",&x,&y,&d);
		if(d==0)
		{
			conn_ect(x,y+N);
			conn_ect(x+N,y);
		}
		else
		{
			conn_ect(x,y);
			conn_ect(x+N,y+N);
		}
	}
	rep1(i,n)
	{
		if(is_in_1(i,i+N))
		{
			printf("0\n");
			return 0;
		}
	}
	rep1(i,n)
	{
		if(get_p_arent(i)==i) ++res;
		//if(get_p_arent(i+N)==i+N) ++res;
	}
	while(--res)
	{
		ans<<=1;
		if(ans>=mod2)
		ans-=mod2;
	}
	printf("%d\n",ans);
	return 0;
}
/* things to check
1. int overflow or long long memory need
2. recursion/array/binary search/dp bounds
3. precision
4. forever loop
5. special cases(n=1,bounds)
*/
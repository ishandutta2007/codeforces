#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
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
//long long , 
//ios_base::sync_with_stdio(false);cin
struct pro{
	long long a;//num need to buy
	long long b;//need buy num to 1
	pro(long long c=0,long long d=0)
	{
		a=c;b=d;
	}
	bool operator<(const pro&c)
	{
		return b<c.b;
	}
};
int n;
long long c,d;
pro f[100005];
int lind,rind;
long long cnt,money;
long long needbuy;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rind=n;
	for(int i=0;i<n;++i)
	{
		cin>>c>>d;
		f[i]=pro(c,d);
	}
	sort(f,f+n);
	while(rind>lind)
	{
		if(cnt>=f[lind].b)
		{
			money+=f[lind].a;
			cnt+=f[lind].a;
			++lind;
		}
		else
		{
			needbuy=min(f[rind-1].a,f[lind].b-cnt);
			money+=(needbuy<<1);
			cnt+=needbuy;
			if(f[rind-1].a==needbuy)
			--rind;
			else
			f[rind-1].a-=needbuy;
		}
	}
	cout<<money<<endl;
	return 0;
}
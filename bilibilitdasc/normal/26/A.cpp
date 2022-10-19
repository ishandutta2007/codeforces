#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define per1(i,n) for(int i=(n);i>=1;i--)
#define repk(i,a,b) for(int i=(a);i<=(b);i++)
#define perk(i,a,b) for(int i=(a);i>=(b);i--)
#define rep0(i,a,b) for(int i=(a);i<(b);i++)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
#define g(x) cout<<#x<<'='<<x<<endl
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
set<int> ept;
set<int> h;
set<int> ____;
set<int> is_almost_prime(int a)
{
	if(a==1) return ept;
	for(int i=2,_s=sqrt(a);i<=_s;i++)
	{
		if(a%i==0)
		{
			h=is_almost_prime(a/i);
			h.insert(i);
			return h;
		}
	}
	____=ept;
	____.insert(a);
	return ____; 
} 
bool iap(int a)
{
	return is_almost_prime(a).size()==2;
}
int main()
{
	int n,cnt=0;
	#if 1
	cin>>n;
	for(int i=6;i<=n;i++)
	{
		if(iap(i))
		{
			cnt++;
		}
	}
	cout<<cnt<<endl;
	#else
	#endif
	return 0;
}
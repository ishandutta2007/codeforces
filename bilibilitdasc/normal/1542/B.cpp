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
int t;
long long n,a,b,res;
void Q()
{
	res=1;
	cin>>n>>a>>b;
	if(a==1)
	{
		if((n-1)%b==0)
		{
			cout<<"Yes"<<endl;
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
	else
	{
		while(res<=n)
		{
			if((n-res)%b==0)
			{
				cout<<"Yes"<<endl;
				return ;
			}
			res*=a;
		}
		cout<<"No"<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	Q();
	return 0;
}
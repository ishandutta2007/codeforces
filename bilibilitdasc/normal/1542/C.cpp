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
//int p[21]={1,2,3,4,5,7,8,9,11,13,16,17,19,23,25,27,29,31,32,37,41};
ll l[21]={1,2,6,12,60,420,840,2520,27720,360360,720720,12252240,232792560,5354228880ll,26771144400ll,80313433200ll,2329089562800ll,72201776446800ll,144403552893600ll,5342931457063200ll,219060189739591200ll};
int d[21]={0,2,1,1,1,2,1,1,2,2,3,1,2,4,2,2,2,2,1,5,4};
int t;
long long a;
long long res;
void Q()
{
	cin>>a;
	res=0;
	for(int i=0;i<20;++i)
	{
		res+=a/l[i]%mod2*d[i+1]%mod2;
		if(res>=mod2) res-=mod2;
	}
	cout<<res<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--)
	Q();
	return 0;
}
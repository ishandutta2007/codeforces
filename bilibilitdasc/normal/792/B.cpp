#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
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
int n,k;
vector<int> v;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) v.pb(i);
	while(k--)
	{
		int a;
		scanf("%d",&a);
		a%=v.size();
		rotate(v.begin(),v.begin()+a,v.end());
		printf("%d%c",v[0],(k)?(' '):'\n');
		v.erase(v.begin());
	}
	return 0;
}
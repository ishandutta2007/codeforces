#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,n) for(int i=(n)-1;i>=0;i--)
#define prt(n) cout<<(n)<<endl
#define elif else if
#define str string
#define pb push_back
#define mp make_pair
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//cin
long long wait(long long a,long long b)
{
	if(a%b==0) return 0;
	return b-a%b;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		long long p,a,b,c;
		cin>>p>>a>>b>>c;
		cout<<min(wait(p,a),min(wait(p,b),wait(p,c)))<<endl;
	}
	return 0;
}
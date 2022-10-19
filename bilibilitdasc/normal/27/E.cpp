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
const int p[30]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113};
const long long inf=1111111111111111111ll;
const long long ten=1000000000000000000ll;
long long pw(long long a,long long b)
{
	if(pow(a,b)>ten) return inf;
	long long ans=1;
	for(;b;b>>=1,a*=a)
	{
		if(b&1) ans*=a;
	}
	return ans;
}
long long getans(int cntd,int up,int cntp)
{
	if(cntd==1) return 1;
	if(cntp>=30) return inf;
	long long ans=inf;
	for(int i=2;i<=up;i++)
	{
		if(cntd%i==0)
		{
			long long pwr=pw(p[cntp],i-1);
			if(pwr==inf) continue;
			long long res=getans(cntd/i,i,cntp+1);
			if(res==inf) continue;
			if(pwr>ten/res) continue;
        	if(ans>pwr*res) ans=pwr*res;
		}
	}
	return ans;
}
int cnt;
int main()
{
	cin>>cnt;
	cout<<getans(cnt,cnt,0)<<endl;
	return 0;
}
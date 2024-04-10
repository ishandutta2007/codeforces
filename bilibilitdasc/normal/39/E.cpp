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
long long n;
int dp[31705][35];
bool chk(int a,int b)
{
	long long res=1;
	while(b--)
	{
		res*=a;
		if(res>=n) return 0;
	}
	return 1;
}
int func(int a,int b)//1 for now lose
{
	if(dp[a][b]!=0x3f3f3f3f) return dp[a][b];
	if(!chk(a,b)) return dp[a][b]=-1;
	if(a==1&&(1ll<<b)>=n) return dp[a][b]=0;
	if(b==1&&1ll*a*a>=n) return dp[a][b]=(((n^a)&1)?1:-1);
	return dp[a][b]=-(max(func(a+1,b),func(a,b+1)));
}
int res,a,b;
int main()
{
	cin>>a>>b>>n;
	memset(dp,0x3f,sizeof(dp));
	res=func(a,b);
	if(res==1) cout<<"Stas";
	else if(res==-1) cout<<"Masha";
	else cout<<"Missing";
	cout<<endl;
	return 0;
}
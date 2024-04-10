#include <bits/stdc++.h>
//#define CinCout
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define debugv(x) cout<<#x<<'='<<x<<",line "<<__LINE__-1<<endl
#define debug cout<<"at line "<<__LINE__-1<<" in function "<<__FUNCTION__<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
#ifdef CinCout
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define YES cout<<"YES"<<endl
#define NO cout<<"NO"<<endl
#else
#define Yes puts("Yes")
#define No puts("No")
#define YES puts("YES")
#define NO puts("NO")
#endif
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);???cin
int n;
string s[2005];
vector<int> nxt[2005][27];
bool isin[2005][27]; 
int nxt2[2005][27];
pair<int,int> dp[2005][2005];
int m;
int t[2005];
string st;
int l;
int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n;
	rep(i,n)
	{
		cin>>s[i];
		rep1(j,26)
		{
			nxt[i][j].resize(s[i].size()+1);
			nxt[i][j][s[i].size()]=-1;
		}
	//	cout<<"Right Now"<<endl; 
		for(int j=s[i].size()-1;j>=0;--j)
		{
			rep1(_,26) nxt[i][_][j]=nxt[i][_][j+1];
			nxt[i][s[i][j]&31][j]=j+1;
		}
	//	for(int j=0;j<=s[i].size();++j) for(int k=1;k<=26;++k)
	//	{
	//		cout<<"Next "<<i<<" "<<j<<" "<<char(k+96)<<" "<<nxt[i][k][j]<<endl;
	//	}
	}
	memset(nxt2,-1,sizeof(nxt2));
	per(i,n)
	{
		rep1(j,26)
		{
			isin[i][j]=(s[i].find(char(j|96))<s[i].size());
		}
	}
	cin>>m;
	rep(i,m)
	{
		cin>>t[i];
	}
	per(i,m)
	{
		rep1(j,26)
		{
			nxt2[i][j]=nxt2[i+1][j];
			if(i<m-1&&isin[t[i+1]-1][j]) nxt2[i][j]=i+1; 
		//	cout<<"next"<<" "<<i<<" "<<char(j|96)<<" "<<nxt2[i][j]<<endl;
		}
	}
	cin>>st;
	l=st.size();
	for(int i=0;i<=l;++i) for(int j=0;j<=i;++j) dp[i][j]=mp(1145141919,1145141919);
	for(int i=0;i<=l;++i) dp[i][0]=mp(0,0);
//	cout<<"Right Now"<<endl;
	for(int i=0;i<l;++i)
	{
	//	cout<<"Right"<<endl;
		for(int j=0;j<=i;++j)
		{
		//	cout<<"Left"<<' '<<i<<' '<<j<<endl;
			if(dp[i][j].fi!=1145141919)
			{
				dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
			//	cout<<"Sir"<<' '<<dp[i][j].fi<<' '<<dp[i][j].se<<' '<<endl; 
				if(nxt[t[dp[i][j].fi]-1][st[i]&31][dp[i][j].se]!=-1)
				{
			//		cout<<"What"<<endl;
					dp[i+1][j+1]=min(dp[i+1][j+1],mp(dp[i][j].fi,nxt[t[dp[i][j].fi]-1][st[i]&31][dp[i][j].se]));
			//		cout<<"Hell"<<endl;
				}
				else if(nxt2[dp[i][j].fi][st[i]&31]!=-1)
				{
			//		cout<<"Hello"<<endl;
					dp[i+1][j+1]=min(dp[i+1][j+1],mp(nxt2[dp[i][j].fi][st[i]&31],nxt[t[nxt2[dp[i][j].fi][st[i]&31]]-1][st[i]&31][0]));
			//		cout<<"World"<<endl;
				}
			//	cout<<"Madam"<<endl;
			}
		//	cout<<"Then"<<endl;
		}
	//	cout<<"Now"<<endl;
	}
	for(int i=l;i>=0;--i)
	{
		if(dp[l][i].fi!=1145141919)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}
/* things to check
1.  int overflow or long long memory need
2.  recursion/array/binary search/dp/loop bounds
3.  precision
4.  special cases(n=1,bounds)
5.  delete debug statements
6.  initialize(especially multi-tests)
7.  = or == , n or m ,++ or -- , i or j , > or >= , < or <=
8.  keep it simple and stupid
9.  do not delete, use // instead
10. operator priority
11. is there anything extra to output?
12. ...
*/

/* something to think about
1. greedy? dp? searching? dp with matrix/ segment tree? binary search?
2. If contains "not", why not ?????? or few affect?
*/
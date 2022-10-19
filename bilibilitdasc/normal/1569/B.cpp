#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,_##i##__end=(n);i<_##i##__end;++i)
#define per(i,n) for(int i=(n)-1;i>=0;--i)
#define rep1(i,n) for(int i=1,_##i##__end=(n);i<=_##i##__end;++i)
#define per1(i,n) for(int i=(n);i>=1;--i)
#define repk(i,a,b) for(int i=(a),_##i##__end=(b);i<=_##i##__end;++i)
#define perk(i,a,b) for(int i=(a),_##i##__end=(b);i>=_##i##__end;++i)
#define rep0(i,a,b) for(int i=(a),_##i##__end=(b);i<_##i##__end;++i)
#define pb push_back
#define mp make_pair
#define debug(x) cout<<#x<<'='<<x<<endl
#define nextp next_permutation
#define pq priority_queue
#define fi first
#define se second
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
int t,n,l;
char s[55];
char with[55][55];
vector<int> won;
void Q()
{
	scanf("%d%s",&n,s);
	memset(with,0,sizeof(with));
	won.clear();
	rep(i,n)
	{
		if(s[i]=='1')
		{
			rep(j,n)
			{
				if(i==j) with[i][j]='X';
				else with[i][j]=with[j][i]='=';
			}
		}
		else
		won.pb(i);
	}
	l=won.size();
	//cout<<l<<endl;
	if(l&&l<3)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	rep(i,l)
	{
		with[won[i]][won[(i+1)%l]]='+';
		with[won[(i+1)%l]][won[i]]='-';
	}
	rep(i,n) rep(j,n)
	{
		if(!with[i][j])
		{
			if(i==j) with[i][j]='X';
			else with[i][j]='=';
		}
	}
	rep(i,n)
	{
		printf("%s\n",with[i]);
	}
}
int main()
{
	scanf("%d",&t);
	while(t--)
	Q();
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
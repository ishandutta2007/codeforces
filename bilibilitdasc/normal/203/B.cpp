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
typedef long long ll;
using namespace std;
const ll mod1=998244353;
const ll mod2=1000000007;
//ios_base::sync_with_stdio(false);cin
const int N=1010;
bool a[N][N];
const int dx[9]={0,0,0,1,1,1,2,2,2};
const int dy[9]={0,1,2,0,1,2,0,1,2};
int ax,ay;
bool c;
bool chk(int x,int y)
{
	for(int i=0;i<9;i++)
	{
		c=1;
		ax=x-dx[i];
		ay=y-dy[i];
		for(int j=0;j<9;j++)
		{
			if(!a[ax+dx[j]][ay+dy[j]])
			{
				c=0;
				break;
			}
		}
		if(c) return 1;
	}
	return 0;
}
int n,m;
int q1,q2;
int main()
{
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>q1>>q2;
		a[++q1][++q2]=1;
		if(chk(q1,q2))
		{
			cout<<i+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0; 
}
/*
4 11
1 1
1 2
1 3
2 2
2 3
1 4
2 4
3 4
3 2
3 3
4 1

4 12
1 1
1 2
1 3
2 2
2 3
1 4
2 4
3 4
3 2
4 2
4 1
3 1

4 15
1 1
1 2
1 3
1 4
1 5
2 1
2 2
2 3
2 4
2 5
3 1
3 2
3 4
3 3
3 5

*/
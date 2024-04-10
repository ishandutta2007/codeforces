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
stack<int> p;
stack<int> put;
queue<int> pp;
bool done[100005];
void solve()
{
	int n;
	scanf("%d",&n);
	fill(done,done+n+1,0);
	for(int i=0;i<n;i++)
	{
		int tmp;
		scanf("%d",&tmp);
		p.push(tmp);
	}
	int mx=n;
	while(!p.empty())
	{
		done[p.top()]=1;
		put.push(p.top());
		if(p.top()==mx)
		{
			while(done[mx]) 
			{
				mx--;
			}
			while(!put.empty())
			{
				pp.push(put.top());
				put.pop();
			}
		}
		p.pop();
	}
	while(!pp.empty())
	{
		cout<<pp.front();
		pp.pop();
		if(pp.empty()) cout<<endl;
		else cout<<' ';
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
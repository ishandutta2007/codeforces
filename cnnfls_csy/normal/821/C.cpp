#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include<iomanip>
#define sqr(x) (x)*(x)
#define ll long long
using namespace std;
priority_queue<ll,vector<ll>,greater<ll>/**/> q;
stack<ll> s;
ll n,m,i,j,x,ans,now;
string st;
int main()
{
	cin>>n;
	for (i=1;i<=2*n;i++)
	{
		cin>>st;
		if (st[0]=='a')
		{
			cin>>x;
			s.push(x);
		}
		else
		{
			now++;
			if (s.empty())
			{
				q.pop();
			}
			else if (s.top()==now)
			{
				s.pop();
			}
			else
			{
				ans++;
				while (!s.empty())
				{
					q.push(s.top());
					s.pop();
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
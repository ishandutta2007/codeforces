#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<stack>
#define sqr(x) (x)*(x)
using namespace std;
string st,ans;
stack<int> s;
int n,m,i,j,x;
bool fi=1;
int main()
{
	cin>>n;
	while (cin>>st)
	{
		if (!fi&&s.empty())
		{
			cout<<"Error occurred";
			return 0;
		}
		if (fi) fi=0;
		if (st=="pair")
		{
			if (!s.empty())
			{
				x=s.top()+1;
				s.pop();
				s.push(x);
				if (s.top()==2) ans+=",";
					//else ans+=">";
			}
			s.push(0);
			ans+="pair<";
		}
		else
		{
			if (!s.empty())
			{
				x=s.top()+1;
				s.pop();
				s.push(x);
				if (s.top()==2) ans+=",";
					//else ans+=">";
			}
			ans+="int";
		}
		while (!s.empty()&&s.top()==2)
		{
			s.pop();
			ans+=">";
		}
	}
	if (!s.empty())
	{
		cout<<"Error occurred";
		return 0;
	}
	cout<<ans;
	return 0;
}
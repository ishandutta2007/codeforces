#include <bits/stdc++.h>

using namespace std;

int n,k;
int h[200001];
stack<int> a;
int mi;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	mi=1;
	a.push(n+1);
	for (int i=0;i<k;++i)
	{
		cin>>h[i];
		if (a.top()<h[i])
		{
			cout<<-1<<endl;
			return 0;
		}
		a.push(h[i]);
		while (a.top()==mi)
		{
			a.pop();
			++mi;
		}
	}
	for (int i=0;i<k;++i) cout<<h[i]<<' ';
	while (a.size())
	{
		for (int i=a.top()-1;i>=mi;--i) cout<<i<<' ';
		mi=a.top()+1;
		a.pop();
	}
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		set<int> S;
		int x,t;
		cin>>x;
		while(x--) scanf("%d",&t),S.insert(t);
		cout<<S.size()<<endl;
	}
	return 0;
}
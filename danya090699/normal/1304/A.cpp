#include <bits/stdc++.h>
using namespace std;
main()
{
	//freopen("input.txt", "r", stdin);
	int t;
	cin>>t;
	while(t)
    {
        t--;
        int x, y, a, b;
        cin>>x>>y>>a>>b;
        cout<<((y-x)%(a+b) ? -1 : (y-x)/(a+b))<<"\n";
    }
}
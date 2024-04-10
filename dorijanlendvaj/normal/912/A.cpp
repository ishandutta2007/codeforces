#include <bits/stdc++.h>

using namespace std;

long long a,b,c,d,e,f,g;

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin>>a>>b>>c>>d>>e;
	f=2*c+d;
	g=d+3*e;
	cout<<max(0ll,f-a)+max(0ll,g-b)<<endl;
}
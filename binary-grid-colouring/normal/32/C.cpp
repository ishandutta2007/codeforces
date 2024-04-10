#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
pair< pair<int,int>, int> pii[123456];

ll n,m,d;

ll cal(ll i)
{
	if(i % d == 0)return i;
	else return ( i / d + 1) * (i % d);
}
int main()
{
	cin>>n>>m>>d;
	cout<<cal(n)*cal(m)<<endl;
	return 0;
}
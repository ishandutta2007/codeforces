#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int a1,b1,c1;
	int a2,b2,c2;
	cin>>a1>>b1>>c1;
	cin>>a2>>b2>>c2;
	if(a1 == 0 && b1 == 0 && c1 != 0) cout<<0<<endl;
	else if(a2 == 0 && b2 == 0 && c2 != 0) cout<<0<<endl;
	else if(a1*b2 == b1*a2 && b1*c2 == c1*b2 && c1*a2 == a1*c2) cout<<-1<<endl;
	else if(a1*b2 == b1*a2)cout<<0<<endl;
	else cout<<1<<endl;
	return 0;
}
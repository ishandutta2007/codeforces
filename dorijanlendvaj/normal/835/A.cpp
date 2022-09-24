#include <bits/stdc++.h>

using namespace std;

int a,b,c,d,e;

int main()
{
	cin>>a>>b>>c>>d>>e;
	if (a*b+d*2<a*c+e*2) cout<<"First"<<endl;
	else if (a*b+d*2>a*c+e*2) cout<<"Second"<<endl;
	else cout<<"Friendship"<<endl;
}
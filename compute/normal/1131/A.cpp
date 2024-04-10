#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long  w1,h1,w2,h2;
	cin>>w1>>h1>>w2>>h2;
	long long ans=2*(w1+2)+h1*2-w2+(h2-1)*2+w2+2;
	cout<<ans<<endl;
}
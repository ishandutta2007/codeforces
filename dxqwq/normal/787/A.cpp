#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
    if((d-b)%__gcd(a,c)) return printf("-1")*0;
    while(b!=d) if(b<d) b+=a; else d+=c;
    cout<<b;
	return 0;
}
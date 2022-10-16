#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	b=min(b,c);
	if(a+b<=d)
		cout<<a*e+b*f;
	else
		if(e<f)
			if(b<=d)
				cout<<b*f+(d-b)*e;
			else
				cout<<d*f;
		else
			if(a<=d)
				cout<<a*e+(d-a)*f;
			else
				cout<<d*e;
}
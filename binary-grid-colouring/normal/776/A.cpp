#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	cin>>a>>b;
	cout<<a<<" "<<b<<endl;
	int n;
	string c,d;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>d;
		if(a==c)a=d;else b=d;
		cout<<a<<" "<<b<<endl;
	}
	return 0;
}
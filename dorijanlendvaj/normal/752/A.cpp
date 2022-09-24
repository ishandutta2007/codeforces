#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,k;
	cin>>a>>b>>k;
	cout<<(k+2*b-1)/(2*b)<<' '<<((k-1)%(2*b))/2+1<<' ';
	if (k%2) cout<<"L"<<endl;
	else cout<<"R"<<endl;
}
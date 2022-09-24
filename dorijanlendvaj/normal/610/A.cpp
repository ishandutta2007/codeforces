#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{
	cin>>n;
	cout<<n/4-1+(n%4)/2-(n/4-1+(n%4)/2)*(n%2)<<endl;
}
#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n,m,a,b;
	cin>>n>>m>>a>>b;
	long long d1=(n/m)*m;
	cout<<min(b*(n-d1),a*(m+d1-n));
	return 0;
}
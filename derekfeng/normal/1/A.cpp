#include <bits/stdc++.h>
using namespace std;
int used[1000000];
int main(){
	long long n,m,k;
	cin>>n>>m>>k;
	cout<<((n+k-1)/k)*((m+k-1)/k);
	return 0;
}
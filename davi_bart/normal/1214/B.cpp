#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,a,b;
		cin>>a>>b>>N;
		a=min(min(N,abs(N-a-b)),min(a,b));
		cout<<a+1;
		return 0;
}
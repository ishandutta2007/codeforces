#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N,a,b;
		cin>>N>>a>>b;
		cout<<(1<<a)-1+N-a<<" "<<(1<<b)-1+(1<<(b-1))*(N-b);

		return 0;
}
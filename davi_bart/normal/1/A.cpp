#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll N,M,A;
    cin>>N>>M>>A;
    cout<<(N/A+((N/A)*A<N))*(M/A+((M/A)*A<M));
    return 0;
}
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a;
    cin>>a;
    cout<<(a.back()-'0')%2;
    return 0;
}
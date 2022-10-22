#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 1e6 + 100;
ll n;
int main(){
    cin >> n;
    if(n==1) cout << 9 << ' ' << 8;
    else cout << n*3 << ' ' << n*2;
    return 0;
}
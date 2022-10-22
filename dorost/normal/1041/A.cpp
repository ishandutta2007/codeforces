#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    ll n, x, mini = 1e9 + 1, maxi = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x < mini){
            mini = x;
        }
        if (x > maxi){
            maxi = x;
        }
    }
    cout << (maxi - mini) - n + 1;
}
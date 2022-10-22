#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main(){
    int n;
    cin >> n;
    for (int i = n; true; i++){
        int m = i, sum = 0;
        while (m){
            sum += m % 10;
            m /= 10;
        }
        sum %= 4;
        if (sum == 0){
            cout << i;
            break;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    m = (240 - m) / 5;
    int sum;
    for (int i = 1;true; i++){
        sum += i;
        if (sum > m){
            cout << min(i -  1, n);
            break;
        }
    }
}
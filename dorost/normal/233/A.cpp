#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    if (n % 2){
        cout << -1;
    }else {
        for (int i = 1; i <= n; i++){
            if (i % 2){
                cout << i + 1 << ' ';
            }else {
                cout << i - 1 << ' ';
            }
        }
    }
}
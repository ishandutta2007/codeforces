#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = n - 2; i >= 0; i--){
        if (a[i] != a[i + 1]){
            cout << i + 1;
            break;
        }
    }
}
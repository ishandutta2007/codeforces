#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, x, a = 0, b = 0;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x > 0){
            a += x;
        }else {
            b += -x;
        }
    }
    cout << a + b;
}
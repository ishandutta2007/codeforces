#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    for (int x = 1; x < 10; x++){
        if (n * x % 10 == m || n * x % 10 == 0) {
            cout << x;
            return 0;
        }
    }
}
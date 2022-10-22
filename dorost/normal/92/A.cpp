#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m;
    cin >> n >> m;
    while (true){
        for(int i = 1; i <= n; i++){
            if (i > m){
                cout << m;
                return 0;
            }
            m -= i;
        }
    }
}
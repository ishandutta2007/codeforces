#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, m, l, r;
    char a, b;
    string s;
    cin >> n >> m >> s;
    for (int i = 0;i < m; i++){
        cin >> l >> r >> a >> b;
        for (int j = l - 1; j < r; j++){
            if (s[j] == a){
                s[j] = b;
            }
        }
    }
    cout << s;
}
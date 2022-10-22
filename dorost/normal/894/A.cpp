#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string s;
    int b = 0,ans = 0;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'Q'){
            b++;
        }
    }
    for (int i = 0; i < s.size(); i++){
        int a = 0;
        if (s[i] != 'A')
            continue;
        for (int j = 0; j < i; j++){
            if (s[j] == 'Q'){
                a++;
            }
        }
        ans += a * (b - a);
    }
    cout << ans;
}
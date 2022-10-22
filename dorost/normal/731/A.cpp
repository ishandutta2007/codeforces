#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    string s;
    cin >> s;
    char c = 'a';
    int sum = 0;
    for (int i = 0; i < s.size(); i++){
        sum += min (abs(s[i] - c), 26 - abs(s[i] - c));
        c = s[i];
    }
    cout << sum;
}
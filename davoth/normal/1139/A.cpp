#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt=0;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0; i<n; i++){
        if((s[i]-'0')%2==0) cnt+=i+1;
    }
    cout << cnt;
    return 0;
}
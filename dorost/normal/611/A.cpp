#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    string s;
    cin >> n >> s >> s;
    if(s[0] == 'w'){
        cout << 52 + (n > 4 && n < 7 ? 1 : 0);
    }else{
        if(n < 30){
            cout << 12;
        }else if(n == 31){
            cout << 7;
        }else{
            cout << 11;
        }
    }
}
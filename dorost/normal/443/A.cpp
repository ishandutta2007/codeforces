#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    map <char,bool> mp;
    char ch;
    while(cin >> ch){
        if(ch >= 'a' && ch <= 'z'){
            mp[ch] = true;
        }
    }
    cout << mp.size() << '\n';
    return 0;
}
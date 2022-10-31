//https://codeforces.com/problemset/problem/1207/E

#include <bits/stdc++.h>
using namespace std;

int main(){
    cout << "? ";
    for(int i = 0; i<100; i++){
        cout << i << " ";
    }
    cout << endl;
    fflush(stdout);
    int re; cin >> re;
    re = (re/128)*128;
    cout << "? ";
    for(int i = 1; i<101; i++){
        cout << i*128 << " ";
    }
    cout << endl;
    fflush(stdout);
    int re2; cin >> re2;
    re2 = re2 - (re2/128)*128;
    cout << "! ";
    cout << re+re2 << endl;
    fflush(stdout);
}
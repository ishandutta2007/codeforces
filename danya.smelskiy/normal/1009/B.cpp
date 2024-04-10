#include <bits/stdc++.h>
using namespace std;

string s;
int c;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=0;i<s.size();++i)
        if (s[i]=='1') ++c;
    for (int i=0;i<s.size();++i) {
        if (s[i]=='0') {
            cout<<"0";
            continue;
        }
        if (s[i]=='1') continue;
        while (c>0) {
            --c;
            cout<<"1";
        }
        cout<<"2";
    }
    while (c>0) {
        --c;
        cout<<"1";
    }
}
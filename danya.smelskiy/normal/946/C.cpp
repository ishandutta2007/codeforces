#include <bits/stdc++.h>
using namespace std;


string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    char last='a';
    for (int i=0;i<s.size();++i) {
        char c=s[i];
        if (c<=last && last<='z') {
            s[i]=last;
            last++;
        }
    }
    if (last<='z') {
        cout<<"-1";
    } else cout<<s;
}
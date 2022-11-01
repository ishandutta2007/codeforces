#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int a,b;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>s;
    for (int i=0;i<s.size();++i) {
        if (i&1) {
            if (s[i]=='0') ++a;
            else ++b;
        } else {
            if (s[i]=='0') ++b;
            else ++a;
        }
    }
    cout<<min(a,b);
}
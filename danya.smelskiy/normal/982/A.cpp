#include <bits/stdc++.h>
using namespace std;

int n;
string s;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    cin>>s;
    for (int i=1;i<n;++i) {
        if (s[i]=='1' && s[i-1]=='1') {
            cout<<"No";
            return 0;
        }
    }
    for (int i=0;i<n;++i) if (s[i]=='0') {
        bool t=false;
        if (i>0 && s[i-1]=='1') t=true;
        if (i<n-1 && s[i+1]=='1') t=true;
        if (!t) {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
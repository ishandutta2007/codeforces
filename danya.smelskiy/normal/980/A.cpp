#include <bits/stdc++.h>
using namespace std;



string s;
int c1,c2;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    for (int i=0;i<s.size();++i)
        if (s[i]=='o') ++c1;
        else ++c2;
    if (!c1) {
        cout<<"YES";
        return 0;
    }
    if (c2%c1==0) cout<<"YES";
    else cout<<"NO";
}
#include <bits/stdc++.h>
using namespace std;





int n;
string s;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    while (t--) {
        cin>>n>>s;
        int l=0;
        int r=n-1;
        bool t=false;
        while (l<r) {
            int x=s[l]-'a';
            int y=s[r]-'a';
            ++l;
            --r;
            if (x==y) {
                continue;
            }
            if ((x+2)==y || (y+2)==x) continue;
            t=true;
        }
        if (t) cout<<"NO"<<'\n';
        else cout<<"YES"<<'\n';
    }
}
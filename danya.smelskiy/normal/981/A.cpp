#include <bits/stdc++.h>
using namespace std;



string s;
int ans;
int n;


inline bool f(string s) {
    int l=0;
    int r=s.size()-1;
    while (l<=r) {
        if (s[l]!=s[r]) return true;
        ++l;
        --r;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    for (int i=0;i<n;++i) {
        string last="";
        for (int j=i;j<n;++j) {
            last+=s[j];
            if (f(last)) ans=max(ans,j-i+1);
        }
    }
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;



string s;
int n;
int ans;
int last;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    s+=s;
    for (int i=0;i<s.size();++i) {
        if (i==0 || s[i]!=s[i-1]) ++last;
        else last=1;
        ans=max(ans,last);
    }
    ans=min(ans,n);
    cout<<ans;
}
#include <bits/stdc++.h>
using namespace std;

string s;
long long mx,ans;
long long a[30];
int k;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    cin>>k;
    for (int i=0;i<26;++i) {
        cin>>a[i];
        mx=max(mx,a[i]);
    }
    for (int i=0;i<s.size();++i)
        ans+=(i+1ll)*a[s[i]-'a'];
    long long n=s.size();
    ++n;
    for (int i=1;i<=k;++i) {
        ans+=mx*n;
        ++n;
    }
    cout<<ans;
}
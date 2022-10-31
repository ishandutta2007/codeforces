#include <bits/stdc++.h>
using namespace std;


int n;
long long a[500005];
long long ans,pref[500005],suff[500005];
string s;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    cin>>s;
    for (int i=1;i<=n;++i) {
        pref[i]=pref[i-1];
        if (s[i-1]=='B') pref[i]+=a[i];
    }
    for (int i=n;i>0;--i) {
        suff[i]=suff[i+1];
        if (s[i-1]=='B') suff[i]+=a[i];
    }
    long long last=0;
    for (int i=0;i<=n;++i) {
        if (i && s[i-1]=='A') last+=a[i];
        ans=max(ans,suff[i+1]+last);
    }
    last=0;
    for (int i=n+1;i>0;--i) {
        if (i<=n && s[i-1]=='A') last+=a[i];
        ans=max(ans,pref[i-1]+last);
    }
    cout<<ans;
}
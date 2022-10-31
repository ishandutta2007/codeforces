#include <bits/stdc++.h>
using namespace std;


string s;
int n;
int ans;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    n=s.size();
    ans=1e9;
    for (int i=0;i<(1<<n)-1;++i) {
        string cur="";
        int cnt=0;
        for (int j=0;j<n;++j)
            if (!(i&(1<<j))) cur+=s[j];
            else ++cnt;
        if (cur[0]=='0') continue;
        int number=0;
        for (int j=0;j<cur.size();++j)
            number=(number*10+cur[j]-'0');
        int z=sqrt(number);
        if (z*z==number) ans=min(ans,cnt);
    }
    if (ans==1e9) cout<<"-1";
    else cout<<ans;

}
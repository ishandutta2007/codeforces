#include <bits/stdc++.h>
using namespace std;

int n,a,b,c,ans,x;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b;
    c=0;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x==1) {
            if (a) --a;
            else if (b) { --b; ++c; }
            else if (c) --c;
            else ++ans;
        } else {
            if (b) --b;
            else ans+=2;
        }
    }
    cout<<ans;
}
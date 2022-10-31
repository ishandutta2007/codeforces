#include <bits/stdc++.h>
using namespace std;

int n,q;
int ans[1000005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    int pos1=1,pos2=2;
    long long d=0;
    while (q--) {
        int tp;
        long long x;
        cin>>tp;
        if (tp==1) {
            cin>>x;
            pos1=(pos1+x+n)%n;
            pos2=(pos2+x+n)%n;
            if (pos1==0) pos1=n;
            if (pos2==0) pos2=n;
        } else {
            if (pos1&1) ++pos1;
            else --pos1;
            if (pos2&1) ++pos2;
            else --pos2;
        }
    }
    for (int i=1;i<=n;i+=2) {
        ans[pos1]=i;
        pos1+=2;
        pos1%=n;
        if (pos1==0) pos1=n;
    }
    for (int i=2;i<=n;i+=2) {
        ans[pos2]=i;
        pos2+=2;
        pos2%=n;
        if (pos2==0) pos2=n;
    }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}
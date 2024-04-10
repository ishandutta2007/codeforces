#include <bits/stdc++.h>
using namespace std;

int n;
int a[205];


main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        for (int j=1;j<=n;++j) {
            int x;
            cin>>x;
            if (i==j) continue;
            for (int k=0;k<=30;++k)
                if (x&(1<<k)) a[i]|=(1<<k),a[j]|=(1<<k);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<a[i]<<" ";
}
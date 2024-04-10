#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int b[200005];
int c[200005];
int sz;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if (x) a[++sz]=x;
    }
    sz=0;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if (x) b[++sz]=x;
    }
    for (int i=1;i<n;++i)
    if (b[i]==a[1]) {
        int pos=i;
        for (int j=1;j<n;++j) {
            c[j]=b[pos++];
            if (pos==n) pos=1;
        }
    }
    for (int i=1;i<n;++i)
    if (a[i]!=c[i]) {
        cout<<"NO";
        return 0;
    }
    cout<<"YES";
}
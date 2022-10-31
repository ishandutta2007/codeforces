#include <bits/stdc++.h>
using namespace std;

int n,m,c;
int a[1005];
int sz1,sz2;
int x;

int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>c;
    c=(c+1)/2;
    for (int i=1;i<=m;++i) {
        cin>>x;
        int pos=0;
        if (x<=c) {
            for (int i=1;i<=sz1;++i)
            if (a[i]>x) {
                pos=i;
                break;
            }
            if (!pos) pos=++sz1;
        } else {
            for (int i=1;i<=sz2;++i)
            if (a[n-i+1]<x) {
                pos=n-i+1;
                break;
            }
            if (!pos) {
                ++sz2;
                pos=n-sz2+1;
            }
        }
        if (pos<1 || pos>n) assert(false);
        cout<<pos<<endl;
        a[pos]=x;
        if (sz1+sz2>=n) {
            return 0;
        }
    }
    assert(false);
}
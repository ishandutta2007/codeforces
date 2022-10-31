#include <bits/stdc++.h>
using namespace std;

int n;
long long s;
long long a[200005];


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        s+=a[i];
    }
    s=(s/2)+s%2;
    long long s2=0;
    for (int i=1;i<=n;++i) {
        s2+=a[i];
        if (s2>=s) {
            cout<<i;
            return 0;
        }
    }

}
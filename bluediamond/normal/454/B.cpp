#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)1e5+5;
int n,v[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    bool ok=1;
    for(int i=1;i<n;i++) {
        if(v[i]>v[i+1]) {
            ok=0;
            break;
        }
    }
    if(ok) {
        cout<<"0\n";
        return 0;
    }
    int st,dr;
    st=1;
    for(int i=1;i<n;i++) {
        if(v[i]<=v[i+1]) {
            st=i+1;
        }
        else {
            break;
        }
    }
    dr=n;
    for(int i=n-1;i>=1;i--) {
        if(v[i]<=v[i+1]) {
            dr=i;
        }
        else {
            break;
        }
    }
    if(v[n]<=v[1]) {
       /// cout<<st<<" "<<dr<<"\n";
        if(st+1==dr) {
            cout<<n+1-dr<<"\n";
            return 0;
        }
    }
    cout<<"-1\n";

    return 0;
}
/**
4
1 2 1 2

1 2 3
3 1 2
2 3 1
1 2 3

**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=100000;
int n,v[N+5];
string b;
int l=-1000000000;
int r=1000000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
    }
    cin>>b;
    b="F"+b;
    for(int i=5;i<=n;i++) {
        if(b[i]=='1') {
            if(b[i-1]=='0' && b[i-2]=='0' && b[i-3]=='0' && b[i-4]=='0') {
                l=max(l,v[i]+1);
                l=max(l,v[i-1]+1);
                l=max(l,v[i-2]+1);
                l=max(l,v[i-3]+1);
                l=max(l,v[i-4]+1);
            }
        }
        else {
            if(b[i-1]=='1' && b[i-2]=='1' && b[i-3]=='1' && b[i-4]=='1') {
                r=min(r,v[i]-1);
                r=min(r,v[i-1]-1);
                r=min(r,v[i-2]-1);
                r=min(r,v[i-3]-1);
                r=min(r,v[i-4]-1);
            }
        }
    }
    if(l>r)
        l=r;
    cout<<l<<" "<<r<<"\n";
    return 0;
}
/**

**/
#include <bits/stdc++.h>
using namespace std;

int n,k;
int last;
int ans[505][505];
map<int,bool> used;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    if (n==1) {
        if (k==0) {
            cout<<1;
            return 0;
        } else {
            cout<<"-1";
            return 0;
        }
    }
    int z=n/2;
    if (z>k) {
        cout<<"-1";
        return 0;
    }
    k-=z-1;
    cout<<k<<" "<<k*2<<" ";
    used[k]=true;
    used[k+k]=true;
    int last=1;
    for (int i=3;i<=n;++i) {
        if (i&1) {
            while (used[last]) ++last;
            cout<<last<<" ";
            used[last]=true;
        } else {
            int ll=last;
            while (used[last] || __gcd(last,ll)==false) ++last;
            cout<<last<<" ";
            used[last]=true;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

ld pi=3.141592653589793;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    ld ans=0;
    for(int i=0;i<n;i++) {
       // cout<<i<<" : "<<ans<<"\n";
        if(i==0) {
            ans+=pi*v[i]*v[i];
        }
        else {
            if(i%2==0) {
                ans+=pi*v[i]*v[i];
                ans-=pi*v[i-1]*v[i-1];
            }
        }
    }
    if(n%2==0) {
        ans=pi*v[n-1]*v[n-1]-ans;
    }
    cout<<fixed<<setprecision(100)<<ans<<"\n";
    return 0;
}
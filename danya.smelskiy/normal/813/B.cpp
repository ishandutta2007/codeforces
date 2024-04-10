#include <bits/stdc++.h>
using namespace std;
const long long md=1e18;
long long x,y,l,r;
vector<long long> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y>>l>>r;
    long long xx=1;
    while (xx<=r) {
        long long yy=1;
        while (xx+yy<=r) {
            if (xx+yy>=l) v.push_back(xx+yy);
            if (yy>md/y) break;
            yy*=y;
        }
        if (xx>md/x) break;
        xx*=x;
    }
    v.push_back(l-1);
    v.push_back(r+1);
    sort(v.begin(),v.end());
    long long ans=0;
    for (int i=v.size()-2;i>=0;--i) {
        ans=max(ans,v[i+1]-v[i]-1);
    }
    cout<<ans;
}
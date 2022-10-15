#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,ma;
    cin>>n>>ma;
    int p0=0;
    int p1=0;
    vector<int>v(n);
    vector<int>sl;
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++) {
        if(v[i]%2==0)
            p0++;
        else
            p1++;
        if(p0==p1 && i!=n-1)
            sl.push_back(abs(v[i]-v[i+1]));
    }
    sort(sl.begin(),sl.end());
    int ans=0;
    for(auto x:sl) {
        if(x<=ma) {
            ma-=x;
            ans++;
        }
        else
            break;
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,d;
    cin>>n>>d;
    vector<int>v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int ans=2;
    for(int i=1;i<n;i++) {
        int dif=v[i]-v[i-1];
        if(dif==2*d)
            ans++;
        else
            if(dif>2*d)
                ans+=2;
    }
    cout<<ans<<"\n";
    return 0;
}
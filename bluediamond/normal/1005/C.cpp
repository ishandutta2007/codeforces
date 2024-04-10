#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=120000;

int n,v[N+5],ans=0;
map<int,int>mp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>v[i];
        mp[v[i]]++;
    }
    for(int i=1;i<=n;i++) {
        bool g=0;
        for(int j=0;j<=30;j++) {
            int val=(1<<j)-v[i];
            if(val==v[i]) {
                if(mp[val]>=2)
                    g=1;
            }
            else
                if(mp[val]>=1)
                    g=1;
        }
        ans+=1-g;
    }
    cout<<ans<<"\n";
    return 0;
}
/**
**/
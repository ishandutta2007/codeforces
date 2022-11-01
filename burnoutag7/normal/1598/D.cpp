#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[200005],b[200005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    ll ans=0;
    {//all diff
        vector<int> m(n+1);
        for(int i=1;i<=n;i++){
            m[a[i]]++;
        }
        ll p1=0,p2=0;
        for(int i=1;i<=n;i++){
            ans+=p2*m[i];
            p2+=p1*m[i];
            p1+=m[i];
        }
    }
    {//two same
        vector<int> m(n+1);
        vector<vector<int>> g(n+1,vector<int>());
        for(int i=1;i<=n;i++){
            m[b[i]]++;
            g[a[i]].emplace_back(b[i]);
        }
        for(int i=1;i<=n;i++){
            ll psum=0;
            int cnt=0;
            for(int x:g[i]){
                ans+=psum-(ll)cnt*m[x];
                cnt++;
                psum+=n-m[x];
            }
        }
    }
    {//all same
        vector<int> m(n+1);
        for(int i=1;i<=n;i++){
            m[a[i]]++;
        }
        for(int i=1;i<=n;i++)ans-=(ll)m[i]*(m[i]-1)*(m[i]-2)/6*2;
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
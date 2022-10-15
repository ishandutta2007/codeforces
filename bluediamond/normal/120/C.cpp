#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,k,ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) {
        int x;
        cin>>x;
        int cnt=0;
        if(x>=3*k)
            cnt=3*k;
        else
            if(x>=2*k)
                cnt=2*k;
            else
                if(x>=k)
                    cnt=k;
                else
                    cnt=0;
        ans+=x-cnt;
    }
    cout<<ans<<"\n";
    return 0;
}
/**
**/
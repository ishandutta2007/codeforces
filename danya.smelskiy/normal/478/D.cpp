#include <bits/stdc++.h>
using namespace std;
const int md=1e9+7;

int x,y;
int dp[200005];
int ans;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>x>>y;
    if (x>y) swap(x,y);
    dp[0]=1;
    int kol=0;
    for (int i=1;i<=1000;++i) {
        kol+=i;
        if (kol>x+y) {
            kol-=i;
            for (int j=0;j<=x;++j) {
                if (j+y>=kol) ans=(ans+dp[j])%md;
            }
            cout<<ans;
            return 0;
        }
        for (int j=x;j>=i;--j)
            dp[j]=(dp[j]+dp[j-i])%md;
    }
    cout<<0;
}
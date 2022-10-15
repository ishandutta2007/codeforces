#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=(int)1e6+7;
int n,c,f[N],sum[N];

signed main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("___input___","r",stdin);

        int tests;
        cin>>tests;

        for(int tc=1;tc<=tests;tc++){
                cin>>n>>c;
                for(int i=1;i<=c;i++){
                        f[i]=sum[i]=0;
                }
                for(int i=1;i<=n;i++){
                        int x;
                        cin>>x;
                        assert(1<=x&&x<=c);
                        f[x]++;
                }
                for(int i=1;i<=c;i++){
                        sum[i]=sum[i-1]+f[i];
                }
                bool ok=1;
                for(int r=1;r<=c&&ok;r++){
                        if(f[r]) continue;
                        for(int y=1;r*y<=c;y++){
                                if(!f[y]) continue;
                                int first=r*y;
                                int last=min(c,(r+1)*y-1);
                                if(sum[last]-sum[first-1]>0){
                                        ok=0;
                                        break;
                                }
                        }
                }
                if(ok){
                        cout<<"Yes\n";
                }else{
                        cout<<"No\n";
                }
        }
}
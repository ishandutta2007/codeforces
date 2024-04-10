#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

#define int long long

signed main() {
#ifdef ONLINE_JUDGE
          home = 0;
#endif

        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int lim=(int)1e9;


        int t;
        cin>>t;
        while(t--){
                int n,x=1;
                bool ok=1;
                cin>>n;
                for(int i=1;i<=n;i++){
                        if(x>lim){
                                ok=0;
                                break;
                        }
                        x*=3;
                }
                if(ok){
                        cout<<"YES\n";
                        x=1;
                        for(int i=1;i<=n;i++){
                                cout<<x<<" ";
                                x*=3;
                        }
                        cout<<"\n";
                }else{
                        cout<<"NO\n";
                }
        }
}
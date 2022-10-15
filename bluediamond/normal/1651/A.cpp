#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
bool home=1;

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


        int t;
        cin>>t;
        while(t--){
                int n;
                cin>>n;
                cout<<(1<<n)-1<<"\n";
        }
}
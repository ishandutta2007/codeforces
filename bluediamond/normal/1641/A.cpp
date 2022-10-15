#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

const int N=(int)2e5+7;
int n,x,a[N];

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int tests;
        cin>>tests;
        for(int tc=1;tc<=tests;tc++){
                cin>>n>>x;
                int sol=n;
                map<int, int> t;
                for(int i=1;i<=n;i++){
                        cin>>a[i];
                        t[a[i]]++;
                }
                for(auto&it:t){
                        if(it.first%x==0&&t[it.first/x]>0){
                                int take=min(it.second,t[it.first/x]);
                                sol-=2*take;
                                it.second-=take;
                                t[it.first/x]-=take;
                        }
                }
                cout<<sol<<"\n";
        }

        return 0;
}
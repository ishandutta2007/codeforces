#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

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
                int n;
                cin>>n;
                vector<int> a(n);
                map<int,int> fRQ;
                for(auto&x:a){
                        cin>>x;
                        fRQ[x]++;
                }
                bool bad=0;
                for(auto&it:fRQ){
                        if(it.second&1){
                                bad=1;
                        }
                }
                if(bad){
                        cout<<"-1\n";
                        continue;
                }
                vector<pair<int, int>> ops;
                vector<int> lens;

                int extra=0;
                int ninit=n;

                function<void(int)> rev=[&](int pref){
                        /// reverse 0..pref-1
                        extra+=pref;
                        for(int j=0;j<pref;j++){
                                ops.push_back({extra++, a[j]});
                        }
                        reverse(a.begin(),a.begin()+pref);
                        lens.push_back(2*pref);
                };

                while(n>=2){
                        int imax=max_element(a.begin(),a.end())-a.begin();
                        assert(0<=imax&&imax<n);
                        assert(a[imax]==*max_element(a.begin(),a.end()));
                        rev(imax+1);
                        rev(n);
                        n--;
                        a.pop_back();
                }

                for(int i=1;i<=ninit/2;i++){
                        lens.push_back(2);
                }


                int sl=0;

                cout<<(int)ops.size()<<"\n";
                for(auto&x:ops){
                        cout<<x.first<<" "<<x.second<<"\n";
                }
                cout<<(int)lens.size()<<"\n";
                for(auto&x:lens){
                        cout<<x<<" ";
                        sl+=x;
                }
                cout<<"\n";
                assert(sl==ninit+2*(int)ops.size());
        }

        return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool home = 1;


typedef long long ll;
const int N=(int)3e5+7;
const ll INF=9223372036854775807;

int n;
int q;
int x[N];
int w[N];
vector<pair<int,int>> la[N];
ll sol[N];


struct OF{
        int l;
        int r;
        ll value;
        OF(int l,int r):l(l),r(r){
                assert(l<=r);
                value=(x[r]-x[l])*(ll)(w[l]+w[r]);
        }
        bool operator < (OF other){
                return l<other.l;
        }
};

ll aib[N];

ll get(int i){
        ll sol=INF;
        while(i){
                sol=min(sol,aib[i]);
                i-=i&(-i);
        }
        return sol;
}

void upd(int i,ll x){
        while(i<=n){
                aib[i]=min(aib[i],x);
                i+=i&(-i);
        }
}

int main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        cin>>n>>q;
        for(int i=1;i<=n;i++){
                aib[i]=INF;
                cin>>x[i]>>w[i];
        }

        for(int i=1;i<=q;i++){
                int l,r;
                cin>>l>>r;
                sol[i]=INF;
                la[l].push_back({r, i});
        }

        vector<OF> offers;

        {
                vector<int> stk;
                for(int i=1;i<=n;i++){
                        while(!stk.empty()&&w[stk.back()]>w[i]) stk.pop_back();
                        if(!stk.empty()) offers.push_back(OF(stk.back(), i));
                        stk.push_back(i);
                }
        }

        {
                vector<int> stk;
                for(int i=n;i>=1;i--){
                        while(!stk.empty()&&w[stk.back()]>w[i]) stk.pop_back();
                        if(!stk.empty()) offers.push_back(OF(i, stk.back()));
                        stk.push_back(i);
                }
        }


        sort(offers.begin(),offers.end());


        for(int l=n;l>=1;l--){

                while(!offers.empty()&&l<=offers.back().l){
                        auto off=offers.back();
                        offers.pop_back();
                        upd(off.r,off.value);
                }

                for(auto&IT:la[l]){
                        int r=IT.first,i=IT.second;
                        sol[i]=get(r);
                }
        }

        for(int i=1;i<=q;i++){
                assert(sol[i]!=INF);
                cout<<sol[i]<<"\n";
        }


        return 0;
}
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int l,r;
    cin>>l>>r;
    r-=l;
    vector<pair<pii,int>> adj;
    adj.push_back({{1,32},l});
    if(r>0) {
        int blocks = __lg(r);
        if(blocks==0){
            adj.push_back({{1,2},r});
            adj.push_back({{2,32},l});
        }
        else {
            int val = (1 << (blocks - 1));
            for (int i = 3; i < 3 + blocks; i++) {
                adj.push_back({{1, i}, val});
                for (int j = i + 1, tv = val / 2; j < 3 + blocks; j++, tv /= 2)adj.push_back({{i, j}, tv});
                adj.push_back({{i, 32}, l});
                val /= 2;
            }
            val = (1 << (blocks - 1));
            adj.push_back({{1, 2}, val * 2-1});
            for (int i = val, ind = 3,toadd=1; i >= 1;i /= 2, ind++) {
                if(r&i){
                    adj.push_back({{2,ind},toadd});
                    toadd+=i;
                }
            }
            adj.push_back({{2,3+blocks},r-2*val+1});
            adj.push_back({{3+blocks,32},l});
        }
    }
    printf("YES\n32 %d\n",sz(adj));
    for(auto x:adj)printf("%d %d %d\n",x.first.first,x.first.second,x.second);
    return 0;
}
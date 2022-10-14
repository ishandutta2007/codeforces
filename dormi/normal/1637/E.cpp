#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T> int sz(const T &a){return int(a.size());}
const int MN=3e5+1;
vector<int> vals[MN];
int arr[MN];
vector<int> bad[MN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n,m,a,b;
        cin>>n>>m;
        vector<int> givenvals;
        bad[0]=vector<int>();
        for(int i=1;i<=n;i++){
            vals[i]=vector<int>();
            bad[i]=vector<int>();
            cin>>arr[i];
            givenvals.push_back(arr[i]);
        }
        sort(givenvals.begin(),givenvals.end());
        givenvals.erase(unique(givenvals.begin(),givenvals.end()),givenvals.end());
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            if(a>b)swap(a,b);
            bad[lower_bound(givenvals.begin(),givenvals.end(),a)-givenvals.begin()].push_back(b);
        }
        for(int i=0;i<sz(givenvals);i++)sort(bad[i].begin(),bad[i].end());
        sort(arr+1,arr+n+1);
        int last=1;
        vector<int> uniquecnts;
        for(int i=1;i<=n;i++){
            if(arr[i]!=arr[last]){
                uniquecnts.push_back(i-last);
                vals[i-last].push_back(arr[last]);
                last=i;
            }
        }
        uniquecnts.push_back(n+1-last);
        vals[n+1-last].push_back(arr[last]);
        sort(uniquecnts.begin(),uniquecnts.end());
        uniquecnts.erase(unique(uniquecnts.begin(),uniquecnts.end()),uniquecnts.end());
        priority_queue<pair<pair<ll,int>,pair<pii,pii>>> q;
        for(int i=0;i<sz(uniquecnts);i++){
            if(sz(vals[uniquecnts[i]])>=2)q.push({{ll(uniquecnts[i]+uniquecnts[i])*ll(vals[uniquecnts[i]].back()+vals[uniquecnts[i]][sz(vals[uniquecnts[i]])-2]),0},{{uniquecnts[i],sz(vals[uniquecnts[i]])-2},{uniquecnts[i],sz(vals[uniquecnts[i]])-1}}});
            for(int j=0;j<i;j++){
                q.push({{ll(uniquecnts[i]+uniquecnts[j])*ll(vals[uniquecnts[i]].back()+vals[uniquecnts[j]].back()),0},{{uniquecnts[i],sz(vals[uniquecnts[i]])-1},{uniquecnts[j],sz(vals[uniquecnts[j]])-1}}});
            }
        }
        while(sz(q)){
            auto cur=q.top();
            q.pop();
            int val1=vals[cur.second.first.first][cur.second.first.second],val2=vals[cur.second.second.first][cur.second.second.second];
            if(val1>val2)swap(val1,val2);
            int ind=lower_bound(givenvals.begin(),givenvals.end(),val1)-givenvals.begin();
            auto it=lower_bound(bad[ind].begin(),bad[ind].end(),val2);
            if(it!=bad[ind].end()&&*it==val2){
                if(cur.second.first.first==cur.second.second.first){
                    if (cur.second.second.second-1>cur.second.first.second) {
                        q.push({{ll(cur.second.first.first + cur.second.second.first) * ll(vals[cur.second.first.first][cur.second.first.second] + vals[cur.second.second.first][cur.second.second.second - 1]), 1},
                                {cur.second.first,                                                                                                                                                               {cur.second.second.first, cur.second.second.second - 1}}});
                    }
                    if (cur.second.first.second > 0 && cur.first.second == 0) {
                        q.push({{ll(cur.second.first.first + cur.second.second.first) * ll(vals[cur.second.first.first][cur.second.first.second - 1] + vals[cur.second.second.first][cur.second.second.second]), 0},
                                {{cur.second.first.first, cur.second.first.second - 1},                                                                                                                          cur.second.second}});
                    }
                }
                else {
                    if (cur.second.second.second > 0) {
                        q.push({{ll(cur.second.first.first + cur.second.second.first) * ll(vals[cur.second.first.first][cur.second.first.second] + vals[cur.second.second.first][cur.second.second.second - 1]), 1},
                                {cur.second.first,                                                                                                                                                               {cur.second.second.first, cur.second.second.second - 1}}});
                    }
                    if (cur.second.first.second > 0 && cur.first.second == 0) {
                        q.push({{ll(cur.second.first.first + cur.second.second.first) * ll(vals[cur.second.first.first][cur.second.first.second - 1] + vals[cur.second.second.first][cur.second.second.second]), 0},
                                {{cur.second.first.first, cur.second.first.second - 1},                                                                                                                          cur.second.second}});
                    }
                }
            }
            else{
                printf("%lli\n",cur.first.first);
                break;
            }
        }
    }
    return 0;
}
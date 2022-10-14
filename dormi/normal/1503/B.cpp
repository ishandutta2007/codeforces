#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
vector<pii> locs[3];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    setbuf(stdout,NULL);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2==0)locs[1].push_back({i,j});
            else locs[2].push_back({i,j});
        }
    }
    int a;
    for(int i=0;i<n*n;i++){
        cin>>a;
        if(a==1){
            if(sz(locs[2])){
                printf("%d %d %d\n",2,locs[2].back().first,locs[2].back().second);
                locs[2].pop_back();
            }
            else{
                printf("%d %d %d\n",3,locs[1].back().first,locs[1].back().second);
                locs[1].pop_back();
            }
        }
        else if(a==2){
            if(sz(locs[1])){
                printf("%d %d %d\n",1,locs[1].back().first,locs[1].back().second);
                locs[1].pop_back();
            }
            else{
                printf("%d %d %d\n",3,locs[2].back().first,locs[2].back().second);
                locs[2].pop_back();
            }
        }
        else{
            if(sz(locs[1])){
                printf("%d %d %d\n",1,locs[1].back().first,locs[1].back().second);
                locs[1].pop_back();
            }
            else{
                printf("%d %d %d\n",2,locs[2].back().first,locs[2].back().second);
                locs[2].pop_back();
            }
        }
    }
    return 0;
}
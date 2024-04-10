#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
ll arr[26][26];
const ll MAXV=1e16;
map<bool,pii> ne;
int n;
bool inbounds(pii loc){
    if(loc.first>=0&&loc.first<n&&loc.second>=0&&loc.second<n)return true;
    return false;
}
int main(){
    setbuf(stdout,NULL);
    cin>>n;
    arr[0][0]=0;//2,3
    ll dist=(n-1)+(n-1);
    for(ll i=1;i<=dist;i++){
        pii loc={0,i};
        if(i>=n)loc={i-(n-1),n-1};
        while(inbounds(loc)){
            if(loc.first%2){
                arr[loc.first][loc.second]=(ll(1)<<ll(i-1));
            }
            else{
                arr[loc.first][loc.second]=0;
            }
            loc.second--;
            loc.first++;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            assert(arr[i][j]<=MAXV);
            printf("%lli ",arr[i][j]);
        }
        printf("\n");
    }
    int q;
    cin>>q;
    ll k;
    while(q--){
        cin>>k;
        printf("%d %d\n",1,1);
        pii loc={0,0};
        for(int i=0;i<dist;i++){
            ne=map<bool,pii>();
            if(loc.first+1<n){
                ne[arr[loc.first+1][loc.second]]={loc.first+1,loc.second};
            }
            if(loc.second+1<n){
                ne[arr[loc.first][loc.second+1]]={loc.first,loc.second+1};
            }
            assert(ne.count(k&(ll(1)<<ll(i))));
            loc=ne[k&(ll(1)<<ll(i))];
            printf("%d %d\n",loc.first+1,loc.second+1);
        }
    }
    return 0;
}
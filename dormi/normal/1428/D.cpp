#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=1e5+1;
int arr[MAXN];
int lowerloc[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    vector<pii> locs;
    queue<int> two;
    queue<int> three;
    for(int i=1;i<=n;i++){
        if(arr[i]==2){
            locs.push_back({i,i});
            two.push(i);
            if(sz(three)){
                locs.push_back({three.front(),i});
                three.pop();
            }
        }
        else if(arr[i]==1){
            if(sz(two)){
                locs.push_back({two.front(),i});
                two.pop();
            }
            else{
                locs.push_back({i,i});
                if(sz(three)){
                    locs.push_back({three.front(),i});
                    three.pop();
                }
            }
        }
        else if(arr[i]==3){
            locs.push_back({i,i});
            if(sz(three)){
                locs.push_back({three.front(),i});
                three.pop();
            }
            three.push(i);
        }
    }
    if(sz(two)||sz(three)){
        printf("-1\n");
    }
    else{
        printf("%d\n",sz(locs));
        for(auto x:locs){
            printf("%d %d\n",x.first,x.second);
        }
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int SZ(const T &a){return int(a.size());}
set<int> solve(int agames, int bgames, int awin, int bwin){
    set<int> res;
    for(int i=0;i<=min(bwin,agames);i++){
        if(bgames>=(bwin-i)){
            res.insert(i+(bgames-(bwin-i)));
        }
    }
    return res;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        set<int> breaks;
        set<int> te=solve((a+b)/2,(a+b+1)/2,a,b);
        for(auto x:te)breaks.insert(x);
        te=solve((a+b+1)/2,(a+b)/2,a,b);
        for(auto x:te)breaks.insert(x);
        printf("%d\n",SZ(breaks));
        int cnt=0;
        for(auto x:breaks)printf("%d%c",x," \n"[(++cnt)==SZ(breaks)]);
    }
    return 0;
}
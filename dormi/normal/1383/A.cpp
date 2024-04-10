#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return (int)a.size();}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        string a,b;
        cin>>a>>b;
        map<int,set<int>> stff;
        bool baf=false;
        for(int i=0;i<n;i++){
            if(b[i]!=a[i]){
                if(b[i]<a[i]){
                    printf("-1\n");
                    baf=true;
                    break;
                }
                stff[a[i]-'a'].insert(b[i]-'a');
            }
        }
        int cnt=0;
        for(int i=0;i<20;i++){
            if(stff.count(i)){
                cnt++;
                int ne=*stff[i].begin();
                stff[i].erase(stff[i].begin());
                for(auto x:stff[i])stff[ne].insert(x);
            }
        }
        if(!baf)printf("%d\n",cnt);
    }
    return 0;
}
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MAXN=3e5+10;
vector<int> insert[MAXN];
vector<int> locs[MAXN];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        set<int> te;
        for(int i=0;i<=n;i++)insert[i]=vector<int>(),locs[i]=vector<int>();
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            locs[a].push_back(i);
        }
        for(int i=1;i<=n;i++){
            int last=-1;
            int madist=0;
            for(auto x:locs[i]){
                madist=max(madist,x-last);
                last=x;
            }
            madist=max(madist,n-last);
            insert[madist].push_back(i);
        }
        for(int i=1;i<=n;i++){
            for(auto x:insert[i])te.insert(x);
            if(!sz(te))printf("-1 ");
            else printf("%d ",*te.begin());
        }
        printf("\n");
    }
    return 0;
}
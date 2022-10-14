#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<int> types;
map<int,int> am;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l=0;
        int a;
        types.clear();
        am.clear();
        for(int i=0;i<n;i++){
            cin>>a;
            types.insert(a);
            am[a]++;
        }
        for(auto x:am)l=max(l,x.second);
        printf("%d\n",max(min(l,sz(types)-1),min(l-1,sz(types))));
    }
    return 0;
}
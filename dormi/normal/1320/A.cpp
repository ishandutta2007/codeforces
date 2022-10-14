#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<lli,lli> cycle;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli a;
    for(int i=0;i<n;i++){
        cin>>a;
        cycle[i-a]+=a;
    }
    lli ans=0;
    for(auto x:cycle){
        ans=max(ans,x.second);
    }
    printf("%lli\n",ans);
    return 0;
}
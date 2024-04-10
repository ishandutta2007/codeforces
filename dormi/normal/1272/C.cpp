#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
vector<pll> chunks;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    string a;
    cin>>a;
    int l=0;
    set<char> can;
    char x;
    for(int i=0;i<k;i++){
        cin>>x;
        can.insert(x);
    }
    for(int i=0;i<sz(a);i++){
        if(!can.count(a[i])){
            if(i-1>=l)chunks.push_back({l,i-1});
            l=i+1;
        }
    }
    if(sz(a)-1>=l)chunks.push_back({l,sz(a)-1});
    lli ans=0;
    for(auto y:chunks){
        ans+=(y.second-y.first+1)*(y.second-y.first+2)/2;
    }
    printf("%lli\n",ans);
    return 0;
}
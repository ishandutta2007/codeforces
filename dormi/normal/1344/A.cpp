#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
set<lli> mods;
lli n;
lli fix(lli a){
    if(a<0){
        lli te=abs(a)/n;
        a+=te*n;
    }
    while(a<0)a+=n;
    return a%n;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        lli a;
        for(lli i=0;i<n;i++){
            cin>>a;
            mods.insert(fix(a+i));
        }
        if(sz(mods)==n)printf("YES\n");
        else printf("NO\n");
        mods.clear();
    }
    return 0;
}
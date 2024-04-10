#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
        string s,t;
        cin>>s>>t;
        int lastparity=0;
        int cur=0;
        for(int i=0;i<sz(s);i++){
            if(i%2!=lastparity&&cur!=sz(t)&&s[i]==t[cur]){
                cur++;
                lastparity=i%2;
            }
        }
        bool work=false;
        work|=(cur==sz(t)&&lastparity==(sz(s)-1)%2);
        lastparity=1;
        cur=0;
        for(int i=0;i<sz(s);i++){
            if(i%2!=lastparity&&cur!=sz(t)&&s[i]==t[cur]){
                cur++;
                lastparity=i%2;
            }
        }
        work|=(cur==sz(t)&&lastparity==(sz(s)-1)%2);
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
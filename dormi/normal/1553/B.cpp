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
        string t,s;
        cin>>s>>t;
        bool work=false;
        for(int i=0;i<sz(s);i++){
            int ptr=0;
            for(int j=i;j<sz(s);j++){
                if(ptr==sz(t)||t[ptr]!=s[j]){
                    break;
                }
                ptr++;
                int left=sz(t)-ptr;
                if(j-left>=0){
                    string te=s.substr(j-left,left);
                    reverse(te.begin(),te.end());
                    work|=(te==t.substr(ptr));
                }
            }
        }
        if(work)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
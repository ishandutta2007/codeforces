#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int MAXN=500;
int32_t main(){
    std::ios_base::sync_with_stdio(false);
    int tc;
    std::cin>>tc;
    for(int ct=0;ct<tc;++ct){
        string s,t;
        cin>>s>>t;
        int marker=s.size();
        int i;
        for(i=t.size()-1;i>=0;--i){
            bool br=false;
            while(true){
                if(marker<=0){
                    br=true;
                    break;
                }
                if(s[marker-1]==t[i]){
                    --marker;
                    break;
                }
                if(marker<2){
                    br=true;
                    break;
                }
                marker-=2;
            }
            if(br)break;
        }
        if(i>=0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}
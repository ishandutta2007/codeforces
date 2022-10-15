#include <bits/stdc++.h>

using namespace std;

bool home=1;

signed main(){
        #ifdef ONLINE_JUDGE
          home = 0;
        #endif

        if(home){
                freopen("iron_man.txt","r",stdin);
        }else{
                ios::sync_with_stdio(0); cin.tie(0);
        }

        int t;
        cin>>t;
        while(t--){
                string s;
                bool r=0,g=0,b=0,ok=1;
                cin>>s;
                for(auto&ch:s){
                        if(ch=='r')r=1;
                        if(ch=='g')g=1;
                        if(ch=='b')b=1;
                        if(ch=='R')ok&=r;
                        if(ch=='G')ok&=g;
                        if(ch=='B')ok&=b;
                }
                if(ok){
                        cout<<"YES\n";
                }else{
                        cout<<"NO\n";
                }
        }

}
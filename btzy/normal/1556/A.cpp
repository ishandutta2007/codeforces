#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        int a,b;
        cin>>a>>b;
        if((a+b)&1){
            cout<<"-1\n";
        }
        else {
            int mid=(a+b)/2;
            if (mid<0){
                cout<<"-1\n";
            }
            else {
                int ans=0;
                if(mid>0)++ans;
                if(a!=b)++ans;
                cout<<ans<<'\n';
            }
        }
    }
}
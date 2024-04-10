#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct!=tc;++ct){
        int n,k1,k2;
        cin>>n>>k1>>k2;
        int m1=0,m2=0;
        for(int i=0;i<k1;++i){
            int tmp;
            cin>>tmp;
            m1=max(m1,tmp);
        }
        for(int i=0;i<k2;++i){
            int tmp;
            cin>>tmp;
            m2=max(m2,tmp);
        }
        if(m1>m2){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    int tc;
    cin>>tc;
    for(int ct=0;ct!=tc;++ct){
        int n;
        cin>>n;
        int high=INT_MIN,low=INT_MAX;
        int highind=-1,lowind=-1;
        int i;
        for(i=0;i<n;++i){
            int tmp;
            cin>>tmp;
            if(high>tmp+i){
                cout<<"YES\n"<<highind+1<<' '<<i+1<<'\n';
                break;
            }
            if(low<tmp-i){
                cout<<"YES\n"<<lowind+1<<' '<<i+1<<'\n';
                break;
            }
            high=tmp+i;
            highind=i;
            low=tmp-i;
            lowind=i;
        }
        if(i<n){
            for(++i;i<n;++i){
                int tmp;
                cin>>tmp;
            }
            continue;
        }
        cout<<"NO\n";
    }
}
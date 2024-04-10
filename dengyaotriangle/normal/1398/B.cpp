#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        string g;
        cin>>g;
        int l=0;g.push_back('0');
        vector<int> f;
        for(int i=0;i<g.size();i++){
            if(g[i]=='1'){
                l++;
            }else{
                if(l){
                    f.push_back(l);
                }
                l=0;
            }
        }
        sort(f.begin(),f.end(),greater<int>());
        int ans=0;
        for(int i=0;i<f.size();i+=2)ans+=f[i];
        cout<<ans<<'\n';
    }
    return 0;
}
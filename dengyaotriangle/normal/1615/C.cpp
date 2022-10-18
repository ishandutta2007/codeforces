#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        int ans=INT_MAX;
        for(int t=0;t<2;t++){
            int c[2]={0,0};
            for(int i=0;i<n;i++){
                if((a[i]^t)!=b[i]){
                    c[(a[i]^t)<b[i]]++;
                }
            }
            if(c[1]==c[0]+t)ans=min(ans,c[0]+c[1]);
        }
        if(ans==INT_MAX)ans=-1;
        cout<<ans<<'\n';
    }
    return 0;
}
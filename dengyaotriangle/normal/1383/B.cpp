#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        int ans=0;
        for(int t=31;t>=0;t--){
            int cnt=0;
            for(auto x:v){
                cnt+=(x>>t)&1;
            }
            if(cnt&1){
                if(cnt&2){
                    if((n-cnt)&1)ans=1;
                    else ans=-1;
                }else{
                    ans=1;
                }
                break;
            }
        }
        if(ans==1)cout<<"WIN\n";
        else if(ans==-1)cout<<"LOSE\n";
        else cout<<"DRAW\n";
    }
    return 0;
}
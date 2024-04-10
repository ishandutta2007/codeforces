#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=10;
        for(int t=0;t<2;t++){
            int d=0;
            for(int i=0;i<10;i++){
                int v;
                if(s[i]=='1')v=1;
                else if(s[i]=='0')v=0;
                else v=(i&1)^t;
                if(i&1)d+=v;
                else d-=v;
                if(d-(10-i-1)/2>0||d+(10-i)/2<0){
                    ans=min(ans,i+1);break;
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
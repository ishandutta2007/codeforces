#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int tot=a+b;
        int t1=tot/2,t2=tot-t1;
        int x=min(t1,a)+min(t2,b),y=min(t1,b)+min(t2,a);
        int l,r;
        r=max(x,y);l=min(tot-x,tot-y);
        vector<int> ret;
        for(int i=l;i<=r;i++){
            if(tot&1)ret.push_back(i);
            else if(~(i-l)&1)ret.push_back(i);
        }
        cout<<ret.size()<<'\n';
        for(int u:ret)cout<<u<<' ';
        cout<<'\n';
        
    }
    return 0;
}
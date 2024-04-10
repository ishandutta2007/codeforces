#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n,p,k;
        cin>>n>>p>>k;
        string s;
        cin>>s;
        int x,y;
        cin>>x>>y;
        vector<int> c(n);
        for(int i=n-1;i>=0;i--){
            c[i]=s[i]=='0';
            if(i+k<n)c[i]+=c[i+k];
        }
        long long ans=LLONG_MAX;
        for(int i=0;i+p-1<n;i++){
            ans=min(ans,i*(long long)y+c[i+p-1]*(long long)x);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=100005;

int n;
long long c[maxn];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>c[i];
        long long ans=LLONG_MAX;
        long long s[2]={c[1],c[2]},m[2]={c[1],c[2]};
        int w[2]={0,0};
        for(int i=2;i<=n;i++){
            ans=min(ans,s[0]-m[0]+m[0]*(n-w[0])+s[1]-m[1]+m[1]*(n-w[1]));
            if((i&1)){
                s[1]+=c[i+1];m[1]=min(m[1],c[i+1]);w[1]++;
            }else{
                s[0]+=c[i+1];m[0]=min(m[0],c[i+1]);w[0]++;
            }
        }        
        cout<<ans<<'\n';
    }
    return 0;
}
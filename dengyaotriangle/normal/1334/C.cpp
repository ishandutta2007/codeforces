#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int n;
long long a[maxn],b[maxn];

int main(){
    ios::sync_with_stdio(0);int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
        long long tot=0,m=0x7fff7fff7fff7fff;
        for(int i=1;i<=n;i++){
            long long w1=max(a[i]-b[(i==1)?n:(i-1)],0ll);
            long long dlt=a[i]-w1;
            tot+=w1;
            m=min(m,dlt);
        }
        cout<<tot+m<<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

void mian(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1;i<=n;i++)if(a[i]!=a[i-1]){
        int cur=0,j=i;
        while(j<=n){
            cur++;
            int l=j+1,r=n,m,nxt=n+1;
            while(l<=r){
                m=(l+r)/2;
                if(a[m]>=a[j]*2-a[i]){
                    nxt=m;
                    r=m-1;
                }else{
                    l=m+1;
                }
            }
            j=nxt;
        }
        ans=max(ans,cur);
    }
    cout<<n-ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int t,n,m,k;
int a[3505];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        m--;
        if(k>m)k=m;
        m-=k;
        int ans=0;
        for(int i=0;i<=k;i++){
            int tmp=0x3f3f3f3f;
            for(int j=0;j<=m;j++){
                tmp=min(tmp,max(a[i+j+1],a[n-(k-i)-(m-j)]));
            }
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }

    return 0;
}
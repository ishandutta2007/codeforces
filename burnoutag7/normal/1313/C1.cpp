#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll mx;
int a[1005];
int m[1005];
int ans[1005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int cur=a[i];
        ll tmp=a[i];
        m[i]=a[i];
        for(int j=i-1;j>=1;j--){
            cur=min(cur,a[j]);
            m[j]=cur;
            tmp+=cur;
        }
        cur=a[i];
        for(int j=i+1;j<=n;j++){
            cur=min(cur,a[j]);
            m[j]=cur;
            tmp+=cur;
        }
        if(tmp>mx){
            mx=tmp;
            memcpy(ans,m,sizeof(ans));
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;

    return 0;
}
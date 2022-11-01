#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

int n,m;
int a[200005],b[200005];
int l[200005],r[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=n,j=m;i>=1;i--){
        while(a[i]<b[j])j--;
        if(!r[j])r[j]=i;
        if(a[i]==b[j]&&!l[j])l[j]=i;
    }
    if(r[0]){
        cout<<0<<endl;
        return 0;
    }
    long long ans=1;
    for(int i=1;i<=m;i++){
        if(!l[i]){
            cout<<0<<endl;
            return 0;
        }
        if(i<m)ans=ans*(l[i+1]-r[i])%mod;
    }
    cout<<ans<<endl;


    return 0;
}
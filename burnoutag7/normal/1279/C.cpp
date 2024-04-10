#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int t,n,m,cnt,mxp;
ll ans;
int a[100005];
int b[100005];
int p[100005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>t;
    while(t--){
        ans=mxp=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            p[a[i]]=i;
        }
        for(int i=1;i<=m;i++){
            cin>>b[i];
            if(mxp>p[b[i]]){
                ans+=1;
            }else{
                mxp=p[b[i]];
                ans+=(p[b[i]]-i)*2+1;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
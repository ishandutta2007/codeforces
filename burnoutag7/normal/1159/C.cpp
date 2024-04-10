#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int b[100005];
int g[100005];
ll ans;
int cnt;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int j=1;j<=m;j++){
        cin>>g[j];
    }

    sort(b+1,b+1+n);
    sort(g+1,g+1+m);

    for(int i=1;i<=n;i++){
        ans+=(1ll*m)*(1ll*b[i]);
    }

    int p=n;

    for(int i=1;i<=m;i++){
        ans+=g[i];
        if(g[i]<b[n]){
            cout<<-1<<endl;
            return 0;
        }
        ans-=b[p];
        if(b[p]<g[i])cnt++;
        if(cnt==m-1){
            cnt=0;
            p--;
        }
    }

    cout<<ans<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
int x[200005];
int dis[200005];
ll sum;
ll f[200005];
ll ans;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    for(int i=1;i<m;i++){
        dis[i]=abs(x[i]-x[i+1]);
        sum+=dis[i];
    }
    for(int i=1;i<m;i++){
        int l=min(x[i],x[i+1]),r=max(x[i],x[i+1]);
        if(l==r)continue;
        //moving index before l don't matter
        f[l]+=l-1;
        f[l+1]-=l-1;//moving l
        f[l+1]--;
        f[r]++;//moving between l & r
        f[r]+=l-(r-l);
        f[r+1]-=l-(r-l);//moving r
    }
    for(int i=1;i<=n;i++){
        f[i]=f[i-1]+f[i];
        cout<<sum+f[i]<<' ';
    }
    cout<<endl;

    return 0;
}
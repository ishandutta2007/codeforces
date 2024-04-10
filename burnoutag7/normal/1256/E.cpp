#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,fa[200005],ans[200005];
pair<int,int> a[200005];
ll f[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--)a[i].first-=a[i-1].first;
    a[1].first=0;
    pair<ll,int> mn(0,0);
    f[0]=0;
    for(int i=1;i<=n;i++){
        mn.first+=a[i].first;
        if(i>3){
            mn=min(mn,make_pair(f[i-3]+a[i].first+a[i-1].first,i-3));
        }
        if(i>2)tie(f[i],fa[i])=mn;
        else f[i]=1e18;
    }
    int x=n,c=0;
    while(x){
        ++c;
        for(int i=x;i>fa[x];i--)ans[a[i].second]=c;
        x=fa[x];
    }
    cout<<f[n]<<' '<<c<<'\n';
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';

    return 0;
}
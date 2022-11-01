#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,p,a[200005],id[200005];
bool u[200005];

void mian(){
    cin>>n>>p;
    for(int i=1;i<=n;i++)cin>>a[i];
    iota(id+1,id+1+n,1);
    sort(id+1,id+1+n,[](int x,int y){
        return a[x]<a[y];
    });
    memset(u+1,0,n);
    int c=n-1;
    ll ans=0;
    for(int i=1;i<=n;i++){
        int x=id[i];
        if(a[x]>p)break;
        for(int j=x;!u[j]&&j>1&&a[j-1]%a[x]==0;j--){
            u[j]=1;
            ans+=a[x];
            c--;
        }
        for(int j=x+1;!u[j]&&j<=n&&a[j]%a[x]==0;j++){
            u[j]=1;
            ans+=a[x];
            c--;
        }
    }
    ans+=(ll)c*p;
    cout<<ans<<'\n';
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
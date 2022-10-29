#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
const int N=500005;
int n,a[N],t[N],id[N];
int vis[N],tot=0;

int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
} 

signed main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        int tmp=a[i];
        for(int j=1;j*j<=tmp;j++){
            if(tmp%j==0){
                if(!vis[j]&&j!=1){
                    id[++tot]=j;
                    vis[j]=tot;
                }
                t[vis[j]]++;
                if(j*j==tmp) continue;
                if(!vis[tmp/j]){
                    id[++tot]=tmp/j;
                    vis[tmp/j]=tot;
                }
                t[vis[tmp/j]]++;
            }
        }
    }
    ll ans=1;
    for(int i=1;i<=tot;i++){
        if(t[i]>=n-1){
            ans=ans*id[i]/gcd(ans,id[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
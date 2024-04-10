#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int n,k;
int pos[100005];
long long f[12][100005];
long long ans;
int x;
void update(int x,int y,long long k){
    while (x<=n) {
        f[y][x]=(f[y][x]+k);
        x=((x|(x+1)));
    }
}
long long get(int x,int y){
    long long res=0;
    while (x>0) {
        res=(res+f[y][x]);
        x=(x&(x+1))-1;
    }
    return res;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>x;
        pos[x]=i;
    }
    if (k==0) {
        cout<<n;
        return 0;
    }
    for (int i=1;i<=n;++i) {
        update(pos[i],1,1);
        for (int j=2;j<=k+1;++j) {
            long long res=get(pos[i]-1,j-1);
            update(pos[i],j,res);
            if (j==k+1) ans=(ans+res);
        }
    }
    cout<<ans;
}
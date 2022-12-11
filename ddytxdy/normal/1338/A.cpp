#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50,inf=1e9+1;
int T,n,a[N],ans,mx;
void solve(){
    scanf("%d",&n);ans=0;mx=-inf;
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);
        ans=max(ans,mx-x);mx=max(mx,x);
    }
    int anss=0;
    while(ans)ans/=2,anss++;
    cout<<anss<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
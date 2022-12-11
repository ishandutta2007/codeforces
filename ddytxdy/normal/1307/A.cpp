#include<bits/stdc++.h>
using namespace std;
const int N=110;
int t,n,m,a[N];
void solve(){
    scanf("%d%d",&n,&m);int ans=0;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=2;i<=n;i++){
        int dat=min(a[i],m/(i-1));
        m-=dat*(i-1);ans+=dat;
    }
    cout<<ans+a[1]<<endl;
}
int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
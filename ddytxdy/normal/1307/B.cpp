#include<bits/stdc++.h>
using namespace std;
const int N=110,inf=1e9;
int t,n,m,a[N];
void solve(){
    scanf("%d%d",&n,&m);int mx=0,fl=0;
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x),mx=max(mx,x);
        if(x==m)fl=1;
    }
    cout<<(fl?1:mx>m?2:(m+mx-1)/mx)<<endl;
}
int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
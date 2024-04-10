#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int t,n,d,ans;
int main(){
    // freopen("test.in","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);ans=2e9;
        for(int l=1,r;l<=d;l=r+1){
            int p=d/l;r=d/p;
            ans=min(ans*1.0,ceil(1.0*d/l)+l-1);
            ans=min(ans*1.0,r-1+ceil(1.0*d/r));
        }
        puts(ans<=n?"Yes":"No");
    }
    return 0;
}
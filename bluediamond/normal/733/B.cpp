#include <bits/stdc++.h>
using namespace std;
const int N=100000;
int n,a[N+5],b[N+5],ax,bx,best,poz;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        ax+=a[i];
        bx+=b[i];
    }
    best=abs(ax-bx);
    //cout<<best<<"\n";
    for(int i=1;i<=n;i++){
        ax=ax-a[i]+b[i];
        bx=bx-b[i]+a[i];
        int cost=abs(ax-bx);
        if(cost>best){
            best=cost;
            poz=i;
        }
        ax=ax+a[i]-b[i];
        bx=bx+b[i]-a[i];
    }
    cout<<poz;
    return 0;
}
/**

**/
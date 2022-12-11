#include<bits/stdc++.h>
using namespace std;
const int N=1e5+50;
int T,n,a[N];
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int nn=n/2;
    for(int i=1;i<=n;i+=2){
        if(a[i]>0)a[i]=-a[i];
        if(a[i+1]<0)a[i+1]=-a[i+1];
    }
    for(int i=1;i<=n;i++)printf("%d ",a[i]);puts("");
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
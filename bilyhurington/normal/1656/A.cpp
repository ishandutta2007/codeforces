#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010];
void solve(){scanf("%d",&n);
    int minx=1,maxx=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>a[maxx]) maxx=i;
        if(a[i]<a[minx]) minx=i; 
    }printf("%d %d\n",minx,maxx);
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
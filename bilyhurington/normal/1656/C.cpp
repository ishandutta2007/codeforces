#include<bits/stdc++.h>
using namespace std;
int T,n,a[100010];
void solve(){
    scanf("%d",&n);
    bool t0=1,t1=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(!a[i]) t1=0;
        else if(a[i]==1) t0=0;
    }
    if(t0) puts("YES");
    else{
        if(!t1) puts("NO");
        else{bool tag=1;
            sort(a+1,a+n+1);
            for(int i=1;i<=n;i++){
                if(a[i]==2) tag=0;
                if(i<n&&a[i]>2&&a[i+1]==a[i]+1) tag=0;
            }
            puts(tag?"YES":"NO");
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int T,n;
int Query(int x){
    printf("? %d\n",x);
    fflush(stdout);int y;
    scanf("%d",&y);return y;
}
void solve(){
    scanf("%d",&n);
    int l=1,r=5000000,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(Query(mid)==1) r=mid;
        else l=mid+1; 
    }
    for(int i=2;i<=n;i++){
        int x=(l-1)/i,t=Query(x);
        if(t>0&&t<=i) l=i*x;
    }
    printf("! %d\n",l);
}
int main(){
    T=1;
    while(T--) solve();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
void work(){
    int n,x,i,j,z,mn,mx,ans=0;
    mn=1e9;mx=0;
    scanf("%d%d",&n,&x);
    bool flg=0;
    for(i=1;i<=n;++i){
        scanf("%d",&z);
        mn=min(z,mn);
        mx=max(z,mx);
        if(mx-mn>2*x){
            mn=mx=z;
            ++ans;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--)work();
    return 0;
}
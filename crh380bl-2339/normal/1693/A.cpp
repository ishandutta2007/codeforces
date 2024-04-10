#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,i,j;
    long long ans=0;
    cin>>t;
    while(t--){
        ans=0;
        bool flg=1;
        bool flg2=0;
        scanf("%d",&n);
        for(i=1;i<=n;++i){
            scanf("%d",&j);
            ans+=j;
            if(ans<0)flg=0;
            if(flg2&&j)flg=0;
            if(ans==0){
                flg2=1;
            }
        }
        if(ans!=0)flg=0;
        if(flg)puts("Yes");
        else puts("No");
    }
    return 0;
}
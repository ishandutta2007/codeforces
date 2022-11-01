#include<bits/stdc++.h>
using namespace std;

int n,q,a[1000005],k[1000005];

bool check(int x){
    int res=0;
    for(int i=1;i<=n;i++)res+=a[i]<=x;
    for(int i=1;i<=q;i++){
        if(k[i]>0)res+=k[i]<=x;
        else res-=-k[i]<=res;
    }
    return res>0;
}

int main(){

    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
    for(int i=1;i<=q;i++){
        scanf("%d",k+i);
    }
    int l=1,r=n,m,ans=0;
    while(l<=r){
        m=l+r>>1;
        if(check(m)){
            r=m-1;
            ans=m;
        }else{
            l=m+1;
        }
    }
    cout<<ans<<endl;

    return 0;
}
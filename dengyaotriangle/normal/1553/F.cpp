#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=300005;

int n;
int a[maxn];
long long ans[maxn],pfx[maxn];
long long bit[maxn];

void chg(int i,long long u){
    for(;i<maxn;i+=i&-i)bit[i]+=u;
}
long long qry(int i){
    long long ret=0;
    for(;i;i-=i&-i)ret+=bit[i];
    return ret;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pfx[i]=pfx[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        int x=a[i];
        chg(x,1);
        for(int z=1;;z++){
            int l=z*x-1,r=(z+1)*x-1;
            bool flg=0;
            if(r>=maxn)r=min(r,maxn-1),flg=1;
            ans[i]-=x*(long long)(qry(r)-qry(l))*z;
            if(flg)break;
        }
    }
    memset(bit,0,sizeof(bit));
    for(int i=1;i<=n;i++){
        int x=a[i];
        ans[i]-=qry(x);
        for(int z=1;;z++){
            int l=z*x;
            if(l>=maxn)break;
            chg(l,x);
        }
    }
    for(int i=2;i<=n;i++)ans[i]+=ans[i-1];
    for(int i=1;i<=n;i++)ans[i]+=i*pfx[i];
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    return 0;
}
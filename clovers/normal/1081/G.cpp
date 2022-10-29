#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int MOD;
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
int mul(int x,int y){return 1ll*x*y%MOD;}
int mul3(int x,int y,int z){return 1ll*x*y%MOD*z%MOD;}
int mul4(int x,int y,int p,int q){return mul(mul(x,y),mul(p,q));}
int qpow(int x,int y){
    int ret=1;
    while(y){
        if(y&1) ret=mul(ret,x);
        x=mul(x,x);
        y>>=1;
    }
    return ret;
}

int n,k,ans=0,sum[N],inv[N];
int cnt1,cnt2,l1=0,l2=0;
void merge_sort(int l,int r,int h){
    if(l>r) return;
    if(h<=1){
        int len=r-l+1;
        ans=add(ans,mul(mul(len-1,len),inv[4]));
        if(!l1) l1=len;
        else if(len!=l1) l2=len;
        if(len==l1) cnt1++;
        else cnt2++;
        return;
    }
    if(l==r) return;
    int mid=(l+r)>>1;
    merge_sort(l,mid,h-1); merge_sort(mid+1,r,h-1);
}

int calc(int len1,int len2){
    int ret=0;
    for(int i=1;i<=len1;i++){
        ret=add(ret,mul(len2,inv[2]));
        ret=sub(ret,sub(sum[i+len2],sum[i]));
    }
    return ret;
}

int main(){
    scanf("%d%d%d",&n,&k,&MOD);
    inv[1]=1;
    for(int i=2;i<=max(n,4);i++) inv[i]=mul(MOD-MOD/i,inv[MOD%i]);
    for(int i=1;i<=n;i++) sum[i]=add(sum[i-1],inv[i]);
    merge_sort(1,n,k);
    ans=add(ans,mul4(cnt1,cnt1-1,inv[2],calc(l1,l1)));
    ans=add(ans,mul4(cnt2,cnt2-1,inv[2],calc(l2,l2)));
    if(l2) ans=add(ans,mul3(cnt1,cnt2,calc(l1,l2)));
    cout<<ans<<endl;
    return 0;
}
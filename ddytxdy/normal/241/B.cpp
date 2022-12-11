#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e4+50,mod=1e9+7,L=31;
int n,a[N],ch[N*L][2],sz[N*L],tot,lim,f[N*L],t[N*L],s[N][L][2],b[L];LL anss,k;
void insert(int id){
    int p=0,x=a[id];
    for(int i=lim,c;i>=0;i--){
        c=(x>>i)&1;
        if(!ch[p][c])ch[p][c]=++tot,f[tot]=id;
        p=ch[p][c];sz[p]++;t[p]=id;
    }
}
int ask(int x,int y){
    int p=0,ret=0;
    for(int i=lim;i>=0;i--){
        int c=(x>>i)&1,d=(y>>i)&1;
        if(!d&&ch[p][c^1])ret+=sz[ch[p][c^1]];
        if(ch[p][c^d])p=ch[p][c^d];
        else break;
    }
    return ret;
}
LL ask2(int x,int y){
    int p=0,ss=0;LL ret=0;
    for(int i=0,xx=x;i<=lim;i++,xx>>=1)b[i]=xx&1;
    for(int i=lim;i>=0;i--){
        int c=b[i],d=(y>>i)&1,q=ch[p][c^1];
        if(!d&&q){
            ss+=sz[q];
            for(int j=0;j<=lim;j++)ret+=1ll*(s[t[q]][j][b[j]^1]-s[f[q]-1][j][b[j]^1])*(1<<j);
        }
        if(ch[p][c^d])p=ch[p][c^d];
        else break;
    }
    k-=ss;
    return ret;
}
bool check(int x){
    LL ret=0;
    for(int i=1;i<=n;i++)ret+=ask(a[i],x);
    return ret<k;
}
int main(){
    scanf("%d%d",&n,&k);k*=2;
    if(!k)puts("0"),exit(0);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);lim=log2(a[n]);
    for(int i=1;i<=n;i++)
        for(int j=0,x=a[i];j<=lim;j++,x>>=1)
            s[i][j][1]=s[i-1][j][1]+(x&1),s[i][j][0]=i-s[i][j][1];
    for(int i=1;i<=n;i++)insert(i);
    LL l=0,r=(1ll<<31)-1,ans=1e9;
    while(l<=r){
        LL mid=(l+r)>>1;
        if(check(mid))ans=mid,r=mid-1;
        else l=mid+1;
    }
    for(int i=1;i<=n;i++)anss+=ask2(a[i],ans);
    anss+=1ll*ans*k;
    cout<<anss/2%mod;   
    return 0;
}
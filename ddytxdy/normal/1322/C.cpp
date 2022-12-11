#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5e5+50,base=999979,mod=1003020631;
int t,n,m,pw[N];LL ans;
LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL read(){
    LL x=0;int c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
struct node{LL x;int hsh;bool friend operator <(node a,node b){return a.hsh<b.hsh;}}a[N];
void solve(){
    scanf("%d%d",&n,&m);pw[0]=1;ans=0;
    for(int i=1;i<=n;i++)pw[i]=1ll*pw[i-1]*base%mod;
    for(int i=1;i<=n;i++)a[i]=(node){read(),0};
    for(int i=1,x,y;i<=m;i++)
        x=read(),y=read(),
        (a[y].hsh+=pw[x])%=mod;
    sort(a+1,a+n+1);
    for(int i=1,j;i<=n;i++){
        if(!a[i].hsh)continue;
        j=i;LL sum=a[i].x;
        while(j<n&&a[j+1].hsh==a[i].hsh)sum+=a[++j].x;
        ans=gcd(ans,sum);i=j;
    }
    cout<<ans<<endl;
}
int main(){
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
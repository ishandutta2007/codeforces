#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e6+10;
int n,m,z[N],pa[N],pb[N],f[N];char a[N],b[N],s[N];LL ans,f2[N],c1[N],c2[N];
void add(int x,int p){for(;x<m;x+=x&-x)f[x]++,f2[x]+=p;}
LL ask(int x){int y=0,z=x;LL y2=0;for(;x;x-=x&-x)y+=f[x],y2+=f2[x];return 1ll*y*(z+1)-y2;}
void getz(){
    z[1]=n;
    for(int i=2,l=0,r=0;i<=m;i++){
        z[i]=i<=r?min(z[i-l+1],r-i+1):0;
        while(s[i+z[i]]==s[1+z[i]])z[i]++;
        if(i+z[i]-1>r)r=i+z[i]-1,l=i;
    }
}
void getp(int *p){
    for(int i=1,l=0,r=0;i<=n;i++){
        p[i]=i<=r?min(z[i-l+1],r-i+1):0;
        while(a[i+p[i]]==s[1+p[i]])p[i]++;
        if(i+p[i]-1>r)r=i+p[i]-1,l=i;
    }
}
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s%s%s",a+1,b+1,s+1);
    a[n+1]=1;b[n+1]=2;s[m+1]=3;
    getz();getp(pa);
    reverse(b+1,b+n+1);reverse(s+1,s+m+1);
    memcpy(a,b,sizeof(b));getz();getp(pb);
    reverse(pb+1,pb+n+1);
    for(int i=1;i<=n;i++)c1[pa[i]]++,c2[pb[i]]++;
    for(int i=n;i;i--)c1[i]+=c1[i+1],c2[i]+=c2[i+1];
    for(int i=1;i<=min(n,m-1);i++)ans+=c1[i]*c2[m-i];
    for(int i=m;i<=n;i++){
        if(pa[i-m+1])add(max(m-pa[i-m+1],1),max(m-pa[i-m+1],1));
        ans-=ask(min(m-1,pb[i]));
    }
    memset(f,0,sizeof(f));memset(f2,0,sizeof(f2));
    for(int i=2;i<=n;i++){
        if(pb[i-1])add(max(m-pb[i-1],1),max(m-pb[i-1],1));
        ans-=ask(min(m-1,pa[i]));
    }
    cout<<ans;
}
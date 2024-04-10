#include<bits/stdc++.h>
#define getbit(x,b) (((x)&(1ll<<(b)))?1:0)
#define ll long long
using namespace std;
const int maxn=1000010,maxk=20;
int i,j,k,n,m,a[maxn],b[maxn];
int pos[maxk+1],ps[maxk+1],w[maxk+1];
ll S,T,w1[maxn],w2[maxn];
int Min[(1<<maxk)+5],Max[(1<<maxk)+5];
int main(){
    string s1,s2;
    cin>>n>>m>>k;
    cin>>s1>>s2;
    for(i=k;i>=1;i--)S=S*2+s1[i-1]-'0';
    for(i=k;i>=1;i--)T=T*2+s2[i-1]-'0';
    for(i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]),--a[i],--b[i];
    w1[n+1]=S;w2[n+1]=T;
    ll now=S;
    for(i=0;i<k;i++)pos[i]=ps[i]=i;
    for(i=n;i>=1;i--){
        swap(ps[a[i]],ps[b[i]]);
        swap(pos[ps[a[i]]],pos[ps[b[i]]]);
        int X=ps[a[i]],Y=ps[b[i]];
        now^=(getbit(now,X)<<X)^(getbit(now,Y)<<X)
            ^(getbit(now,X)<<Y)^(getbit(now,Y)<<Y);
        w1[i]=now;
    }
    now=T;
    for(i=0;i<k;i++)pos[i]=ps[i]=i;
    for(i=n;i>=1;i--){
        swap(ps[a[i]],ps[b[i]]);
        swap(pos[ps[a[i]]],pos[ps[b[i]]]);
        int X=ps[a[i]],Y=ps[b[i]];
        now^=(getbit(now,X)<<X)^(getbit(now,Y)<<X)
            ^(getbit(now,X)<<Y)^(getbit(now,Y)<<Y);
        w2[i]=now;
    }
    int Ans=-1,c1=-1,c2=-1;
    for(i=0;i<(1<<maxk);i++)Min[i]=1e9;
    for(i=0;i<(1<<maxk);i++)Max[i]=-1e9;
    for(i=1;i<=n;i++)Min[w1[i]]=min(Min[w1[i]],i);
    for(i=1;i<=n+1;i++)Max[w2[i]]=max(Max[w2[i]],i);
    for(j=0;j<k;j++)
        for(i=0;i<(1<<k);i++)
            if(i&(1<<j))if(Min[i^(1<<j)]>Min[i])
                Min[i^(1<<j)]=Min[i];
    for(j=0;j<k;j++)
        for(i=0;i<(1<<k);i++)
            if(i&(1<<j))if(Max[i^(1<<j)]<Max[i])
                Max[i^(1<<j)]=Max[i];
    for(i=0;i<(1<<k);i++)
        if(Max[i]-Min[i]>=m){
            int sum=k-(__builtin_popcount(S)+__builtin_popcount(T)-__builtin_popcount(i)*2);
            if(sum>Ans)Ans=sum,c1=Min[i],c2=Max[i];
        }
    cout<<Ans<<endl<<c1<<' '<<c2-1<<endl;
}
/*
00110
00101
*/
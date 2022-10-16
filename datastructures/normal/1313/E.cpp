#include <iostream>
#include <cstdio>
#include <cstring>
#define int long long
using namespace std;
struct BIT{
    int tree[2000005];
    BIT(){
        memset(tree,0,sizeof(tree));
    }
    inline int lowbit(int x){
        return x&(-x);
    }
    inline void add(int pos,int val){
        while(pos<=2000000)tree[pos]+=val,pos+=lowbit(pos);
        return;
    }
    inline int query(int pos){
        int ans=0;
        while(pos)ans+=tree[pos],pos-=lowbit(pos);
        return ans;
    }
}bit1,bit2;
int n,m,ans;
char a[2000005],b[2000005],c[2000005];
int z[2000005],lcp[2000005],lcs[2000005];
inline void GetZ(){
    int l=0,r=0;
    z[1]=m-1;
    for (int i=2;i<=m;i++){
        if (i<=r)z[i]=min(z[i-l+1],r-i+1);
        while(i+z[i]<m&&c[i+z[i]]==c[z[i]+1])z[i]++;
        if (i+z[i]-1>r)l=i,r=i+z[i]-1;
    }
    return;
}
inline void GetLCP(){
    int l=0,r=0;
    for (int i=1;i<=n;i++){
        if (i<=r)lcp[i]=min(z[i-l+1],r-i+1);
        while(i+lcp[i]<=n&&lcp[i]+1<m&&a[i+lcp[i]]==c[lcp[i]+1])lcp[i]++;
        if (i+lcp[i]-1>r)l=i,r=i+lcp[i]-1;
    }
    return;
}
inline void GetLCS(){
    int l=0,r=0;
    for (int i=1;i<=n;i++){
        if (i<=r)lcs[i]=min(z[i-l+1],r-i+1);
        while(i+lcs[i]<=n&&lcs[i]+1<m&&b[i+lcs[i]]==c[lcs[i]+1])lcs[i]++;
        if (i+lcs[i]-1>r)l=i,r=i+lcs[i]-1;
    }
    for (int i=1;i<=n/2;i++)swap(lcs[i],lcs[n-i+1]);
    return;
}
inline void add(int len){
    if (len!=0){
        bit1.add(len,1);
        bit2.add(len,len);
    }
    return;
}
inline void del(int len){
    if (len!=0){
        bit1.add(len,-1);
        bit2.add(len,-len);
    }
    return;
}
inline int query(int x){
    return (bit2.query(m-1)-bit2.query(x))-x*(bit1.query(m-1)-bit1.query(x));
}
signed main(){
    cin>>n>>m;
    scanf("%s%s%s",a+1,b+1,c+1);
    GetZ();
    GetLCP();
    for (int i=1;i<=m/2;i++)swap(c[i],c[m-i+1]);
    for (int i=1;i<=n/2;i++)swap(b[i],b[n-i+1]);
    memset(z,0,sizeof(z));
    GetZ();
    GetLCS();
    int j=1;
    for (int i=1;i<=n;i++){
        while(j<=i+m-2&&j<=n)add(lcs[j]),j++;
        ans+=query(m-lcp[i]-1);
        del(lcs[i]);
    }
    cout<<ans<<endl;
}
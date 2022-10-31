#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int l[N],r[N],b[N],cnt[N],id[N],seg[N],seg2[N],f[N],f2[N];
vector<int> Q[N];
int read(){
    int c=0; char ch=getchar();
    while (ch<'0'||'9'<ch) ch=getchar();
    while ('0'<=ch&&ch<='9') c=c*10+ch-'0',ch=getchar();
    return c;
}
int main(){
    int n=read(),m=read(),k=read(); m=0;
    for (int i=1;i<=n;++i){
        l[i]=read(),r[i]=read()+1;
        b[++m]=l[i],b[++m]=r[i];
    }
    sort(b+1,b+1+m); m=unique(b+1,b+1+m)-b-1;
    for (int i=1;i<=n;++i){
        l[i]=lower_bound(b+1,b+1+m,l[i])-b;
        r[i]=lower_bound(b+1,b+1+m,r[i])-b;
        Q[l[i]].push_back(i);
    }
    for (int s=0;s<1<<10;++s)
        for (int i=0;i<10;++i)
            if (s>>i&1) ++cnt[s];
    int ql=1,qr=0;
    for (int i=1,c=0;i<=m;++i){
        int c2=0;
        for (int j=0;j<c;++j)
            if (r[seg[j]]!=i) id[seg[j]]=c2,seg2[c2++]=seg[j];
        for (int s=0;s<1<<c2;++s) f2[s]=0;
        for (int s=0;s<1<<c;++s){
            int _s=0;
            for (int j=0;j<c;++j)
                if ((s>>j&1)&&r[seg[j]]!=i) _s|=1<<id[seg[j]];
            f2[_s]=max(f2[_s],f[s]);
        }
        int t=(1<<c2)-1;
        for (int j=0;j<Q[i].size();++j) seg2[c2++]=Q[i][j];
        for (int s=0;s<1<<c2;++s) f2[s]=f2[s&t];
        for (int s=0;s<1<<c2;++s) f[s]=f2[s]+(cnt[s]&1?b[i+1]-b[i]:0);
        c=c2; for (int i=0;i<c;++i) seg[i]=seg2[i];
    }
    cout<<f[0]<<endl;
    return 0;
}
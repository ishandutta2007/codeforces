#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

int n,a[300005],b[300005],ap[300005],bp[300005],cp[300005];
map<pair<int,int>,int> mem;

int f(int x,int y){
    if(x>n||y>n)return -1;
    if(mem.find(P(x,y))!=mem.end())return mem[P(x,y)];
    int &res=mem[P(x,y)];
    if(x<=y)res=max(res,f(ap[x],y)+1);
    if(x>=y)res=max(res,f(x,bp[y])+1);
    if(x==y)res=max(res,f(cp[x],cp[x])+1);
    else res=max(res,f(max(x,y),max(x,y)));
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    map<ll,int> m;
    m[0]=0;
    ll s=0;
    memset(ap,0x3f,sizeof(ap));
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
        if(m.find(s)!=m.end())ap[m[s]]=i;
        m[s]=i;
    }
    m.clear();
    m[0]=0;
    s=0;
    memset(bp,0x3f,sizeof(bp));
    for(int i=1;i<=n;i++){
        cin>>b[i];
        s+=b[i];
        if(m.find(s)!=m.end())bp[m[s]]=i;
        m[s]=i;
    }
    m.clear();
    m[0]=0;
    s=0;
    memset(cp,0x3f,sizeof(cp));
    for(int i=1;i<=n;i++){
        s+=a[i]+b[i];
        if(m.find(s)!=m.end())cp[m[s]]=i;
        m[s]=i;
    }
    for(int i=n;i>=1;i--){
        ap[i-1]=min(ap[i-1],ap[i]);
        bp[i-1]=min(bp[i-1],bp[i]);
        cp[i-1]=min(cp[i-1],cp[i]);
    }
    cout<<f(0,0)<<'\n';

    return 0;
}
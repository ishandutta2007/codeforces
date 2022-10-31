
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int maxn = 2e5+100;
#define M_PI 3.1415926535
struct Node{int x,y;};
int st[maxn],top; Node a[maxn];
int rk[maxn];int n,T,l,m;
LL cross(const Node &a,const Node &b,const Node &c){
    return 1LL*(b.x-a.x)*(c.y-a.y)-1LL*(c.x-a.x)*(b.y-a.y);
}
LL cross(int x,int y,int z){return cross(a[x],a[y],a[z]);}
double dis(const Node &a,const Node &b){
    return sqrt(1.0*(a.x-b.x)*(a.x-b.x)+1.0*(a.y-b.y)*(a.y-b.y));
}
bool cmp(int x,int y){
    LL m = cross(a[rk[0]],a[x],a[y]);
    if (m>0)return 1;
    else if (m==0&&dis(a[rk[0]],a[x])<=dis(a[rk[0]],a[y]))return 1;
    else return 0;
}
void work(int n){
    for (int i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        rk[i]=i;
    }
    for (int i=1;i<n;i++){
        if (a[rk[i]].y<a[rk[0]].y||a[rk[i]].y==a[rk[0]].y&&a[rk[i]].x<a[rk[0]].x)swap(rk[i],rk[0]);
    }
    sort(rk+1,rk+n,cmp);top=2;
    st[0]=rk[0];st[1]=rk[1];
    for (int i=2;i<n;i++){
        while (top>=2&&cross(st[top-2],st[top-1],rk[i])<=0)top--;
        st[top++] =rk[i];
    }
}
const ULL Seed2 = 4294967291ull;
const ULL Delta = 1LL*rand()*rand()%Seed2;
ULL calc_hash(const Node& l,const Node& mid,const Node& r){
    ULL ret =1;
    int dx = l.x-mid.x;
    int dy = l.y-mid.y;
    ULL len1 = 1LL*dx*dx%Seed2+1LL*dy*dy%Seed2;
    dx = r.x-mid.x;
    dy = r.y-mid.y;
    ULL len2 = 1LL*dx*dx%Seed2+1LL*dy*dy%Seed2;
    len1%=Seed2;len2%=Seed2;
    ret = ret*len1%Seed2*len2%Seed2;
    LL dot = (1LL*((l.x-mid.x+Seed2)%Seed2)*((r.x-mid.x+Seed2)%Seed2)%Seed2+1LL*((l.y-mid.y+Seed2)%Seed2)*((r.y-mid.y+Seed2)%Seed2)%Seed2)%Seed2;
    ret = ret*((dot+Delta)%Seed2)%Seed2;
    ret = (ret+len1+len2)%Seed2;
    return ret;
}
ULL hasha[maxn*2];
ULL hashb[maxn*2];
ULL Seed_Pool[]={911,146527,19260817,91815541};
ULL Mod_Pool[]={29123,998244353,1000000009,4294967291ull};
struct Hash_1D{
    ULL Seed,Mod;
    ULL bas[maxn];
    ULL sum[maxn];
    void init(int seedIndex,int modIndex,int n){
        Seed = Seed_Pool[seedIndex];
        Mod = Mod_Pool[modIndex];
        bas[0]=1;
        for (int i=1;i<=n;i++){
            bas[i] = bas[i-1]*Seed%Mod;
        }
        for (int i=1;i<=n;i++){
            sum[i] = (sum[i-1]*Seed%Mod+hasha[i-1])%Mod;
        }
    }
    ULL getHash(int l,int r){
        return (sum[r]-sum[l-1]*bas[r-l+1]%Mod+Mod)%Mod;
    }
}hasher;
int main(){
    scanf("%d%d",&n,&m);
    work(n);
    int N = top;
    st[top] = st[0];
    hasha[0] = calc_hash(a[st[N-1]],a[st[0]],a[st[1]]);
    for (int i=1;i<N;i++){
        hasha[i] = calc_hash(a[st[i-1]],a[st[i]],a[st[i+1]]);
    }
    work(m);
    int M = top;
    st[top] = st[0];
    hashb[0] = calc_hash(a[st[M-1]],a[st[0]],a[st[1]]);
    for (int i=1;i<M;i++){
        hashb[i] = calc_hash(a[st[i-1]],a[st[i]],a[st[i+1]]);
    }
    //cout<<N<<" "<<M<<endl;
    if (M!=N){
        puts("NO");
        return 0;
    }
    for (int i=0;i<N;i++){
        hasha[N+i] = hasha[i];
    }
//    for (int i=0;i<2*N;i++){
//        cout<<"hasha["<<i<<"]="<<hasha[i]<<endl;
//    }
    hasher.init(3,1,2*N);
    ULL Seed = Seed_Pool[3];
    ULL Mod = Mod_Pool[1];
    ULL hashVal = 0;
    for (int i=0;i<N;i++){
        hashVal = (hashVal*Seed%Mod+hashb[i])%Mod;
    }
//    cout<<hashVal<<"!"<<endl;
    for (int i=0;i<N;i++){
        ULL temp = hasher.getHash(i+1,i+N);
//        cout<<temp<<endl;
        if (temp == hashVal){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
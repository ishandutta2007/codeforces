#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2010;
int T,n,m;
array<int,3>A[MAXN*MAXN];
char s[MAXN];
set<int>S;
set<array<int,2> >E;
struct DSU{
    int fa[MAXN];
    void init(int n){rep(i,1,n)fa[i]=i;}
    int find(int x){
        if(fa[x]==x)return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y,int flag=0){
        if(!flag && find(x)!=find(y))E.insert({x,y});
        x=find(x);y=find(y);if(x==y)return;
        fa[x]=y;
    }
}dsu;
int p[MAXN],cnt;
int arr1[MAXN],arr2[MAXN],len1,len2;
void process(int L,int R){
    int l=dsu.find(L),r=dsu.find(R);
    cnt=0;
    while(S.size()){
        if(*S.rbegin()<l)break;
        int u=*S.lower_bound(l);
        if(u>r)break;
        S.erase(u);
        p[++cnt]=u;
    }
    assert(cnt!=3); //invalid case
    p[1]=L;p[cnt]=R;
    if(cnt==1){
        S.insert(dsu.find(p[1]));
        return;
    }
    if(cnt==2){
        dsu.merge(p[1],p[2]);
        S.insert(dsu.find(p[1]));
        return;
    }
    len1=len2=0;
    int mid=cnt;
    per(i,cnt-1,1)if(i!=mid){
        if(odd(i))arr1[++len1]=p[i];
        else arr2[++len2]=p[i];
    }
    reverse(arr2+1,arr2+1+len2);
    rep(i,1,len1-1){
        dsu.merge(arr1[i],arr1[i+1]);
    }
    dsu.merge(arr1[len1],p[mid]);
    dsu.merge(arr2[1],p[mid]);
    rep(i,1,len2-1){
        dsu.merge(arr2[i],arr2[i+1]);
    }
    S.insert(dsu.find(p[1]));
}
void solve(){
    cin>>n;E.clear();S.clear();
    rep(i,1,n)S.insert(i);
    dsu.init(n);
    //
    m=0;
    rep(i,1,n){
        cin>>(s+1);
        rep(j,2,n-i+1){
            if(s[j]=='1')A[++m]={j,i,i+j-1};
        }
    }
    sort(A+1,A+1+m);
    rep(i,1,m)process(A[i][1],A[i][2]);


    //
    for(auto u:E){
        cout<<u[0]<<" "<<u[1]<<"\n";
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
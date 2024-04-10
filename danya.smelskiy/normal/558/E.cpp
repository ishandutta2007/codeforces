#include <bits/stdc++.h>
using namespace std;
const int N=370000;
int n,m;
int sz;
bool q[26][N];
int tree[26][N];
int to[26][N];
int kol[26];
int x,y,z;
string s;

inline void push(int x,int y,int ll,int rr){
    if (q[y][x]==false) return;
    q[y][x]=false;
    q[y][x+x]=true;
    q[y][x+x+1]=true;
    int mid=(ll+rr)/2;
    to[y][x+x]=to[y][x];
    to[y][x+x+1]=to[y][x];
    tree[y][x+x]=to[y][x]*(mid-ll+1);
    tree[y][x+x+1]=to[y][x]*(rr-mid);
}

void update(int l,int r,int ll,int rr,int x,int y,int z){
    if (l!=r)
    push(x,y,l,r);
    if (l>r || ll>r || l>rr || ll>rr) return ;
    if (l>=ll && r<=rr) {
        q[y][x]=true;
        to[y][x]=z;
        tree[y][x]=(r-l+1)*z;
        if (l!=r) push(x,y,l,r);
        return;
    }
    int mid=(l+r)/2;
    update(l,mid,ll,rr,x+x,y,z);
    update(mid+1,r,ll,rr,x+x+1,y,z);
    tree[y][x]=tree[y][x+x]+tree[y][x+x+1];
}
int get(int l,int r,int ll,int rr,int x,int y){
    if (l!=r) push(x,y,l,r);
    if (l>r || ll>r || l>rr ||ll>rr) return 0;
    if (l>=ll && r<=rr) {
        return tree[y][x];
    }
    int mid=(l+r)/2;
    return get(l,mid,ll,rr,x+x,y)+get(mid+1,r,ll,rr,x+x+1,y);
}
inline void pr(){
    for (int i=1;i<=n;++i) {
        for (int j=0;j<26;++j)
        if (get(1,sz,i,i,1,j)) {
            cout<<char(j+'a');
            break;
        }
    }
    exit(0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sz=1;
    while (sz<n) sz+=sz;
    cin>>s;
    for (int i=1;i<=n;++i) {
        int x=s[i-1]-'a';
        update(1,sz,i,i,1,x,1);
    }
    for (int i=1;i<=m;++i) {
        cin>>x>>y>>z;
        for(int j=0;j<26;++j){
            kol[j]=get(1,sz,x,y,1,j);
            update(1,sz,x,y,1,j,0);
        }
        if (z==1) {
            int last=x-1;
            for (int j=0;j<26;++j)
            if (kol[j]) {
                ++last;
                update(1,sz,last,last+kol[j]-1,1,j,1);
                last+=kol[j]-1;
            }
        } else {
            int last=x-1;
            for (int j=25;j>=0;--j) {
                if (kol[j]) {
                    ++last;
                    update(1,sz,last,last+kol[j]-1,1,j,1);
                    last+=kol[j]-1;
                }
            }
        }
    }
    pr();
}
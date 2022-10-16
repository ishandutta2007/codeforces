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
const int MAXN=1010;
int n;
int pos[30],arr[30];
char s[MAXN];
map<array<int,2>,int>g;
int cmp(int x,int y){
    return pos[x]>pos[y];
}
int qry(int l,int r){
    if(l==r)return g[{l,r}]=1;
    if(g.find({l,r})!=g.end())return g[{l,r}];
    cout<<"? 2 "<<l<<' '<<r<<endl;
    int num;cin>>num;
    return g[{l,r}]=num;
}
char qry(int l){
    cout<<"? 1 "<<l<<endl;
    char ch;cin>>ch;
    return ch;
}
int main(){
    cin>>n;
    s[1]=qry(1);
    pos[s[1]-'a']=1;
    rep(i,2,n){
        int tot=0;
        rep(j,0,25)if(pos[j])arr[++tot]=j;
        sort(arr+1,arr+1+tot,cmp);
        int L=1,R=tot,ret=-1;
        while(L<=R){
            int mid=(L+R)>>1;
            int num=qry(pos[arr[mid]],i);
            if(num==mid){
                ret=mid;R=mid-1;
            }else{
                L=mid+1;
            }
        }
        if(ret==-1)s[i]=qry(i);
        else s[i]=arr[ret]+'a';
        pos[s[i]-'a']=i;
    }
    cout<<"! "<<(s+1)<<endl;

    return 0;
}
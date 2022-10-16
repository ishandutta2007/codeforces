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
const int MAXN=1e5+100;
int T,n,a[MAXN],b[MAXN],res;
int sortag;
set<int>S;
bool cmp(int x,int y){
    return (x>>sortag&1)>(y>>sortag&1);
}
int check(int L,int R,int d){
    sortag=d;
    sort(a+L,a+R+1,cmp);
    reverse(a+L,a+R+1);
    int c1=0,c2=0;
    rep(i,L,R)if(a[i]>>d&1)c1++;else c2++;
    rep(i,L,R)if(b[i]>>d&1)c2--;else c1--;
    return c1==0 && c2==0;
}
void update(int L,int R,int d){
    sortag=d;
    sort(b+L,b+R+1,cmp);
    rep(i,L,R)if(a[i]>>d&1){
        if(i!=1)S.insert(i-1);
        return;
    }
}
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    res=0;
    S.clear();S.insert(n);
    //
    per(i,29,0){
        int flag=1;
        int pre=0;
        for(auto now:S){
            flag&=check(pre+1,now,i);
            pre=now;
        }
        if(flag){
            res|=(1<<i);
            set<int>tmp=S;
            int pre=0;
            for(auto now:tmp){
                update(pre+1,now,i);
                pre=now;
            }
        }
    }
    //
    cout<<res<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}
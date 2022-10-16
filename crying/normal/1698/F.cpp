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
const int MAXN=510;
int T,n,a[MAXN],b[MAXN];
int tmp[MAXN];
vector<array<int,2> >op;
void solve(int l,int r){reverse(a+l,a+r+1);}
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    op.clear();
    rep(i,1,n){
        if(a[i]==b[i])continue;
        if(i==1){
            cout<<"NO\n";return;
        }
        int flag=0;
        rep(j,i+1,n)if(a[j]==a[i-1] && a[j-1]==b[i]){
            flag=1;
            solve(i-1,j);
            op.push_back({i-1,j});
            break;
        }
        if(flag)continue;
        rep(l,i,n){
            int tag=0;
            rep(r,l+1,n){
                if(a[r-1]==a[i-1] && a[r]==b[i])tag=1;
                if(tag && a[r]==a[l]){
                    flag=1;
                    solve(l,r);
                    op.push_back({l,r});
                    goto END;
                }   
            }
        }
        END:;
        if(!flag){
            cout<<"NO\n";return;
        }
        rep(j,i+1,n)if(a[j]==a[i-1] && a[j-1]==b[i]){
            solve(i-1,j);
            op.push_back({i-1,j});
            break;
        }
    }
    cout<<"YES\n";
    cout<<op.size()<<'\n';
    for(auto p:op)cout<<p[0]<<' '<<p[1]<<'\n';
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}
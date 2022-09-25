#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
#define ull unsigned long long
#define ld long double
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<((int)(a)); i++)
#define rep3(i,b,a) for(int i=(b); i>=((int)(a)); i--)
#define all(a) a.begin(),a.end()
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
//#define inf 2000000000
#define inf 8000000000000000000
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#define ykh mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;
const int maxn=705;
//i_am_noob
int n,m,state[55][55],targeted[55][55],cnt[55]={0},k1,k2,targetx,cnt1=0,x,y;
pii pos[55],target[55];
vector<vector<int>> vec,vec1;
vector<int> vec2;

void moveone(int x1, int y1, int x2, int y2){
    assert(state[x1][y1]!=-1&&state[x2][y2]==-1);
    vec.pb({x1,y1,x2,y2});
    state[x2][y2]=state[x1][y1];
    state[x1][y1]=-1;
    pos[state[x2][y2]]={x2,y2};
}

void Move(int x1, int y1, int x2, int y2){
    if(x1==x2){
        if(y1>y2) rep3(i,y1,y2+1) moveone(x1,i,x1,i-1);
        if(y1<y2) rep2(i,y1,y2) moveone(x1,i,x1,i+1);
    }
    if(y1==y2){
        if(x1>x2) rep3(i,x1,x2+1) moveone(i,y1,i-1,y1);
        if(x1<x2) rep2(i,x1,x2) moveone(i,y1,i+1,y1);
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    rep(m) cin >> pos[i].first >> pos[i].second;
    rep(m) cin >> target[i].first >> target[i].second;
    rep(m) pos[i].first--,pos[i].second--,target[i].first--,target[i].second--;
    rep(n) rep1(j,n) state[i][j]=targeted[i][j]=-1;
    rep(m) state[pos[i].first][pos[i].second]=i;
    rep(m) targeted[target[i].first][target[i].second]=i;
    if(n==1){
        print1(0);
        return 0;
    }
    rep(m) cnt[target[i].first]++;
    rep(n-1) if(cnt[i]+cnt[i+1]<=2){
        targetx=i;
        break;
    }
    cnt[0]=cnt[1]=0;
    rep(n) rep1(j,2){
        if(state[targetx+j][i]+1){
            Move(targetx+j,i,targetx+j,cnt[j]);
            cnt[j]++;
        }
    }
    rep3(i,cnt[1]-1,0){
        Move(targetx+1,i,targetx+1,i+cnt[0]);
        moveone(targetx+1,i+cnt[0],targetx,i+cnt[0]);
    }
    cnt1=cnt[0]+cnt[1];
    rep2(i,targetx+2,n) rep1(j,n) if(state[i][j]+1){
        Move(i,j,targetx+1,j);
        Move(targetx+1,j,targetx+1,cnt1);
        moveone(targetx+1,cnt1,targetx,cnt1);
        cnt1++;
    }
    rep(cnt1) moveone(targetx,i,targetx+1,i);
    rep3(i,targetx-1,0) rep1(j,n) if(state[i][j]+1){
        Move(i,j,targetx,j);
        Move(targetx,j,targetx,cnt1);
        moveone(targetx,cnt1,targetx+1,cnt1);
        cnt1++;
    }
    rep(targetx) rep1(j,n) if(targeted[i][j]+1){
        k1=targeted[i][j];
        x=pos[k1].first,y=pos[k1].second;
        moveone(x,y,x-1,y);
        Move(x-1,y,x-1,j);
        Move(x-1,j,i,j);
    }
    rep(n) if(state[targetx+1][i]+1) moveone(targetx+1,i,targetx,i);
    rep3(i,n-1,targetx+2) rep1(j,n) if(targeted[i][j]+1){
        k1=targeted[i][j];
        x=pos[k1].first,y=pos[k1].second;
        moveone(x,y,x+1,y);
        Move(x+1,y,x+1,j);
        Move(x+1,j,i,j);
    }
    rep(m) if(target[i].first==targetx||target[i].first==targetx+1) vec2.pb(i);
    if(sz(vec2)==1){
        k1=vec2[0];
        Move(pos[k1].first,pos[k1].second,target[k1].first,pos[k1].second);
        Move(target[k1].first,pos[k1].second,target[k1].first,target[k1].second);
    }
    if(sz(vec2)==2){
        k1=vec2[0],k2=vec2[1];
        if(target[k1].first==targetx&&target[k2].first==targetx+1){
            Move(pos[k2].first,pos[k2].second,target[k2].first,pos[k2].second);
            Move(pos[k1].first,pos[k1].second,target[k1].first,target[k1].second);
            Move(pos[k2].first,pos[k2].second,target[k2].first,target[k2].second);
        }
        if(target[k2].first==targetx&&target[k1].first==targetx+1){
            Move(pos[k1].first,pos[k1].second,target[k1].first,pos[k1].second);
            Move(pos[k1].first,pos[k1].second,target[k1].first,target[k1].second);
            Move(pos[k2].first,pos[k2].second,target[k2].first,target[k2].second);
        }
        if(target[k1].first==targetx&&target[k2].first==targetx){
            Move(pos[k2].first,pos[k2].second,pos[k2].first+1,pos[k2].second);
            Move(pos[k1].first,pos[k1].second,target[k1].first,target[k1].second);
            Move(pos[k2].first,pos[k2].second,pos[k2].first,target[k2].second);
            Move(pos[k2].first,pos[k2].second,target[k2].first,target[k2].second);
        }
        if(target[k1].first==targetx+1&&target[k2].first==targetx+1){
            Move(pos[k1].first,pos[k1].second,pos[k1].first+1,pos[k1].second);
            Move(pos[k1].first,pos[k1].second,target[k1].first,target[k1].second);
            Move(pos[k2].first,pos[k2].second,pos[k2].first,target[k2].second);
            Move(pos[k2].first,pos[k2].second,target[k2].first,target[k2].second);
        }
    }
    print1(sz(vec));
    rep(sz(vec)){
        rep1(j,4) print0(vec[i][j]+1);
        cout << "\n";
    }
    return 0;
}
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
const int MOD=Mod2;
const int maxn=300005;
//i_am_noob
int n,a[maxn],b[maxn],l,r,mid,x,Q,cur1=0,cur2=0,ans[maxn]={0};

struct BIT{
	int val[maxn]={0};
	void modify(int x, int y){for(int i=x; i<maxn; i+=i&-i) val[i]+=y;}
	int query(int x, int y){
		int ret=0;
		for(int i=y; i>0; i-=i&-i) ret+=val[i];
		for(int i=x-1; i>0; i-=i&-i) ret-=val[i];
		return ret;
	}
}bit,bit2;

struct query{
    int pos,x,y,val;
}q1[maxn],q2[maxn];

bool comp1(const query q1, const query q2){return q1.x>q2.x;}
bool comp2(const query q1, const query q2){return q1.y>q2.y;}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> Q;
    rep(n) cin >> a[i];
    rep(Q) cin >> q1[i].x >> q1[i].y;
    rep(Q) q1[i].y=n-q1[i].y;
    rep(Q) q1[i].pos=q2[i].pos=i;
    rep(Q) q2[i].x=q1[i].x,q2[i].y=q1[i].y;
    sort(q1,q1+Q,comp1);
    sort(q2,q2+Q,comp2);
    rep(n){
        if(a[i]>i+1){
            b[i]=0;
            bit.modify(b[i]+1,1);
            continue;
        }
        l=0,r=i+1;
        while(l<r){
            mid=l+r>>1;
            x=bit.query(1,mid+1);
            if(x>=a[i]) r=mid;
            else l=mid+1;
        }
        b[i]=l;
        bit.modify(b[i]+1,1);
    }
    rep3(i,n,0){
        if(i!=n) bit2.modify(b[i]+1,1);
        while(cur1<Q&&q1[cur1].x==i){
            q1[cur1].val=bit2.query(i+2,maxn-1);
            ans[q1[cur1].pos]+=q1[cur1].val;
            cur1++;
        }
        while(cur2<Q&&q2[cur2].y==i){
            q2[cur2].val=bit2.query(q2[cur2].x+2,maxn-1);
            ans[q2[cur2].pos]-=q2[cur2].val;
            cur2++;
        }
    }
    rep(Q) print1(ans[i]);
    return 0;
}
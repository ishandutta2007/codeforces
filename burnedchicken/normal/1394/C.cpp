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
int n,a[maxn]={0},b[maxn]={0},c[maxn],mina=inf,maxa=-inf,minb=inf,maxb=-inf,l=0,r=1000000,mid,x,y,z,w,ind[maxn],cnt=0,minnb[maxn],maxdiff[maxn],maxxb[maxn],mindiff[maxn],k,maxl,minr,ans1,ans2;
string str[maxn];
bool flag,flag2;

bool comp(int i, int j){return a[i]<a[j];}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n) cin >> str[i];
    rep(n) rep1(j,sz(str[i])) str[i][j]=='B'?a[i]++:b[i]++;
    rep(n) mina=min(mina,a[i]),maxa=max(maxa,a[i]),minb=min(minb,b[i]),maxb=max(maxb,b[i]);
    rep(n) ind[i]=i;
    sort(ind,ind+n,comp);
    rep(n) c[i]=a[ind[i]];
    rep(n) a[i]=c[i];
    rep(n) c[i]=b[ind[i]];
    rep(n) b[i]=c[i];
    //rep(n) print2(a[i],b[i]);
    //print1("noob");
    minnb[0]=inf;
    rep(n) minnb[i+1]=min(minnb[i],b[i]);
    maxdiff[0]=-inf;
    rep(n) maxdiff[i+1]=max(maxdiff[i],b[i]-a[i]);
    maxxb[0]=-inf;
    rep(n) maxxb[i+1]=max(maxxb[i],b[n-1-i]);
    mindiff[0]=inf;
    rep(n) mindiff[i+1]=min(mindiff[i],b[n-1-i]-a[n-1-i]);
    while(1){
        mid=l+r>>1;
        if(l==r) flag=true;
        y=mina+mid,x=maxa-mid,w=minb+mid,z=maxb-mid;
        if(x>y||z>w){
            l=mid+1;
            continue;
        }
        x=max(x,0ll),z=max(z,0ll);
        k=lower_bound(a,a+n,x+1)-a-1;
        flag2=false;
        rep2(i,x,y+1){
            //print1(i);
            while(k<n-1&&a[k+1]<=i) k++;
            maxl=-inf;
            maxl=max(maxl,maxdiff[k+1]+i-mid);
            maxl=max(maxl,maxxb[n-k-1]-mid);
            minr=inf;
            minr=min(minr,minnb[k+1]+mid);
            minr=min(minr,mindiff[n-k-1]+mid+i);
            //print2(maxl,minr);
            if(minr>=maxl&&(i>0||minr>0)){
                ans1=i,ans2=minr;
                flag2=true;
                break;
            }
        }
        if(flag2) r=mid;
        else l=mid+1;
        if(flag) break;
    }
    print1(l);
    rep(ans1) cout << "B";
    rep(ans2) cout << "N";
    cout << "\n";
    return 0;
}
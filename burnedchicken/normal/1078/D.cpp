#include <bits/stdc++.h>
using namespace std;

#define rep(n) rep1(i,n)
#define rep1(i,n) rep2(i,0,n)
#define rep2(i,a,b) for(int i=a; i<b; i++)
#define rep3(i,a,b) for(int i=a; i>=b; i--)
#define pii pair<int,int>
#define pb push_back
#define sz(a) ((int)a.size())
#define all(a) a.begin(),a.end()
#define pow2(x) (1ll<<(x))
#define inf 1010000000

const int maxn=100005;
int n,a[maxn],vall[maxn][17],valr[maxn][17],curl[maxn],curr[maxn],ans[maxn],lll,rrr;
vector<int> l[17],r[17];

void buildl(vector<int>& vec){
    rep(maxn) vall[i][0]=vec[i];
    rep2(i,1,17) rep1(j,maxn-pow2(i)+1) vall[j][i]=min(vall[j][i-1],vall[j+pow2(i-1)][i-1]);
}

void buildr(vector<int>& vec){
    rep(maxn) valr[i][0]=vec[i];
    rep2(i,1,17) rep1(j,maxn-pow2(i)+1) valr[j][i]=max(valr[j][i-1],valr[j+pow2(i-1)][i-1]);
}

inline int queryl(int l, int r){return min(vall[l][__lg(r-l+1)],vall[r-pow2(__lg(r-l+1))+1][__lg(r-l+1)]);}

inline int queryr(int l, int r){return max(valr[l][__lg(r-l+1)],valr[r-pow2(__lg(r-l+1))+1][__lg(r-l+1)]);}

void extend(int l, int r, int& resl, int& resr){
    if(l<0){
        resl=min(queryl(l+n,n-1)-n,queryl(0,r));
        resr=max(queryr(l+n,n-1)-n,queryr(0,r));
    }
    else if(r>=n){
        resl=min(queryl(l,n-1),queryl(0,r-n)+n);
        resr=max(queryr(l,n-1),queryr(0,r-n)+n);
    }
    else{
        resl=queryl(l,r);
        resr=queryr(l,r);
    }
    if(resr-resl+1>=n) resl=-inf,resr=inf;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    rep(17) l[i].resize(maxn),r[i].resize(maxn);
    cin >> n;
    if(n==1){
        cout << "0\n";
        return 0;
    }
    rep(n) cin >> a[i];
    rep(n) l[0][i]=i-a[i],r[0][i]=i+a[i],curl[i]=curr[i]=i;
    rep2(i,n,maxn) l[0][i]=inf,r[0][i]=-inf;
    rep(n) if(r[0][i]-l[0][i]+1>=n) l[0][i]=-inf,r[0][i]=inf;
    //rep(n) cout << l[0][i] << ' ' << r[0][i] << "\n";
    rep2(i,1,17){
        buildl(l[i-1]),buildr(r[i-1]);
        rep1(j,n){
            if(l[i-1][j]==-inf){
                l[i][j]=-inf,r[i][j]=inf;
                continue;
            }
            extend(l[i-1][j],r[i-1][j],l[i][j],r[i][j]);
            //if(i<=2) cout << i << ' ' << j << ' ' << l[i][j] << ' ' << r[i][j] << "\n";
        }
    }
    rep3(i,16,0){
        buildl(l[i]),buildr(r[i]);
        rep1(j,n){
            extend(curl[j],curr[j],lll,rrr);
            if(lll!=-inf) curl[j]=lll,curr[j]=rrr,ans[j]+=pow2(i);
        }
    }
    rep(n) cout << ans[i]+1 << " \n"[i==n-1];
    return 0;
}
#include <bits/stdc++.h>
#include <bits/extc++.h>

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
const int maxn=5005;
//i_am_noob
int n,x,y,p,k,a[maxn]={0},ind[maxn],lpd[maxn],cnt[maxn][826],dep[maxn]={0},l,r,l1,r1,l2,r2,cur[826]={0},cur2,cnt2[826]={0},cnt3,cnt4,ans=0;

void find_prime(){
	rep(maxn) lpd[i]=-1;
    rep2(i,2,maxn){
        if(lpd[i]==-1){
            lpd[i]=i;
            for(int j=i*i; j<maxn; j+=i) if(lpd[j]==-1) lpd[j]=i;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    rep(n){
        cin >> x;
        a[x]++;
    }
    find_prime();
    ind[2]=0,x=1;
    rep2(i,3,maxn) if(lpd[i]==i) ind[i]=x++;
    memset(cnt,0,sizeof(cnt));
    rep2(i,1,maxn){
        rep1(j,x) cnt[i][j]=cnt[i-1][j];
        dep[i]=dep[i-1];
        y=i;
        while(y>1){
            cnt[i][ind[lpd[y]]]++;
            dep[i]++;
            y/=lpd[y];
        }
    }
    l=0,r=maxn-2,k=0,cur2=-1;
    rep2(i,2,maxn){
        if(lpd[i]==i) p=i,k=0;
        k+=a[i];
        if(k>n/2){
            cur2=ind[p];
            cur[ind[p]]++;
            l=p;
            break;
        }
    }
    if(cur2==-1){
        rep(maxn) ans+=a[i]*dep[i];
        print1(ans);
        return 0;
    }
    rep(maxn) if(cnt[i][cur2+1]){
        r=i-1;
        break;
    }
    while(1){
        cnt3=cnt4=0,l1=l2=inf,r1=r2=-inf;
        rep2(i,l,r+1){
            if(cnt[i][cur2]>cur[cur2]) cnt3+=a[i],l1=min(l1,i),r1=max(r1,i);
            else if(cur2&&cnt[i][cur2-1]) cnt4+=a[i],l2=min(l2,i),r2=max(r2,i);
        }
        if(cnt3>n/2){
            cur[cur2]++;
            l=l1,r=r1;
        }
        else if(cnt4>n/2){
            cur2--;
            cur[cur2]++;
            l=l2,r=r2;
        }
        else{
            y=0;
            rep(826) y+=cur[i];
            rep(maxn){
                k=0;
                rep3(j,x-1,0){
                    k+=min(cnt[i][j],cur[j]);
                    if(cnt[i][j]!=cur[j]) break;
                }
                ans+=a[i]*(y+dep[i]-2*k);
            }
            print1(ans);
            return 0;
        }
    }
    return 0;
}
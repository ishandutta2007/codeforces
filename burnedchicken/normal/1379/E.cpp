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
#define pi 3.14159265358979323846264338328
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
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod2;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=100005;
//i_am_noob
int n,k,ans[maxn];

bool solve(int l, int len, int cnt){
    if(len==1) return true;
    if(len==3){
        if(cnt) return false;
        ans[l+1]=l,ans[l+2]=l;
        return true;
    }
    if(len==5){
        if(cnt!=1) return false;
        ans[l+1]=l,ans[l+4]=l;
        solve(l+1,3,0),solve(l+4,1,0);
        return true;
    }
    if(len==7){
        if(cnt!=0&&cnt!=2) return false;
        if(cnt){
            ans[l+1]=l,ans[l+6]=l;
            solve(l+1,5,1),solve(l+6,1,0);
            return true;
        }
        ans[l+1]=l,ans[l+4]=l;
        solve(l+1,3,0),solve(l+4,3,0);
        return true;
    }
    if(len==9){
        if(cnt!=1&&cnt!=3) return false;
        if(cnt==1){
            ans[l+1]=l,ans[l+4]=l;
            solve(l+1,3,0),solve(l+4,5,1);
            return true;
        }
        ans[l+1]=l,ans[l+8]=l;
        solve(l+1,7,2),solve(l+8,1,0);
        return true;
    }
    if(len==11){
        if(cnt==0||cnt>4) return false;
        if(cnt%2){
            ans[l+1]=l,ans[l+4]=l;
            solve(l+1,3,0),solve(l+4,7,cnt-1);
            return true;
        }
        ans[l+1]=l,ans[l+2]=l;
        solve(l+1,1,0),solve(l+2,9,cnt-1);
        return true;
    }
    if(__builtin_popcountll(len+1)==1){
        if(cnt==1) return false;
        if(cnt==0){
            ans[l+1]=l,ans[l+1+len/2]=l;
            solve(l+1,len/2,0),solve(l+1+len/2,len/2,0);
            return true;
        }
    }
    else{
        if(cnt==0) return false;
        if(cnt==1){
            rep2(i,1,20){
                if(len-pow2(i)==pow2(i+1)-1){
                    ans[l+1]=l,ans[l+pow2(i)]=l;
                    solve(l+1,pow2(i)-1,0),solve(l+pow2(i),pow2(i+1)-1,0);
                    return true;
                }
                if(max(pow2(i)-1,len-pow2(i))<min(pow2(i)-1,len-pow2(i))*2){
                    ans[l+1]=l,ans[l+pow2(i)]=l;
                    solve(l+1,pow2(i)-1,0),solve(l+pow2(i),len-pow2(i),1);
                    return true;
                }
            }
        }
        if(__builtin_popcountll(len-1)==1&&cnt==2){
            ans[l+1]=l,ans[l+4]=l;
            solve(l+1,3,0),solve(l+4,len-4,1);
            return true;
        }
    }
    ans[l+1]=l,ans[l+2]=l;
    solve(l+1,1,0),solve(l+2,len-2,cnt-1);
    return true;
}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> n >> k;
    if(n%2==0||(n>1&&k>=n/2)){
        print1("NO");
        return 0;
    }
    ans[0]=-1;
    if(!solve(0,n,k)){
        print1("NO");
        return 0;
    }
    print1("YES");
    rep(n) print0(ans[i]+1);
    return 0;
}
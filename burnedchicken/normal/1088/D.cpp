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
#define eps 1e-9
#define sz(a) ((int)a.size())
#define pow2(x) (1ll<<(x))
#define ceiling(a,b) (((a)+(b)-1)/(b))
#define print0(a) cout << (a) << ' '
#define print1(a) cout << (a) << '\n'
#define print2(a,b) cout << (a) << ' ',print1(b)
#define print3(a,b,c) cout << (a) << ' ',print2(b,c)
#define print4(a,b,c,d) cout << (a) << ' ',print3(b,c,d)
#ifdef i_am_noob
#define debug(a) print2(#a,a)
#else
#define debug(a)
#endif
#define ordered_set tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

using namespace std;
using namespace __gnu_pbds;

const int Mod=1000000007,Mod2=998244353;
const int MOD=Mod;

inline int add(int a, int b){return (a+b>=MOD?a+b-MOD:a+b);}
inline int sub(int a, int b){return (a+MOD-b>=MOD?a-b:a+MOD-b);}
int Pow(int a, int b){
	if(!b) return 1;
	int tmp=Pow(a*a%MOD,b>>1);
	return (b&1?tmp*a%MOD:tmp);
}
inline int inverse(int n){return Pow(n,MOD-2);}

const int maxn=2005;
//i_am_noob
int a=0,b=0,c=0,num1,num2;
vector<int> vec1,vec2;

int query(int x, int y){
    print3("?",x,y);
    cout << flush;
    int ret;
    cin >> ret;
    return ret;
}

signed main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	rep3(i,29,0){
	    num1=query(c+pow2(i),0);
	    num2=query(c,pow2(i));
	    if(num1==num2){
            vec1.pb(i);
            vec2.pb(num1);
            c+=pow2(i);
	    }
	    else{
            if(num1==-1) a+=pow2(i),b+=pow2(i);
	    }
	}
	if(vec1.empty()){
        print3("!",a,b);
        cout << flush;
        return 0;
	}
	rep(sz(vec1)-1){
	    if(vec2[i]==1) a+=pow2(vec1[i+1]);
	    else b+=pow2(vec1[i+1]);
	}
	c-=pow2(vec1[0]);
	if(query(c,0)==1) a+=pow2(vec1[0]);
	else b+=pow2(vec1[0]);
	print3("!",a,b);
	cout << flush;
	return 0;
}
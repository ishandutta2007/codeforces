#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

inline int add(int a, int b){return (a+b>=MOD)?a+b-MOD:a+b;}
inline void inc(int& a, int b){a = add(a, b);}
inline int sub(int a, int b){return (a-b<0)?a-b+MOD:a-b;}
inline void dec(int &a, int b){a = sub(a, b);}
inline int mul(int a, int b){return 1ll*a*b%MOD;}
inline void grow(int &a, int b){a = mul(a, b);}

int ckmin(int &a, int b){return (b<a)?a=b:a;}
int ckmax(int &a, int b){return (b>a)?a=b:b;}

int n, q;
map<pair<int, int>, char> mp;
int cnttot, cntgood;

int main(){
	// freopen("a.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> q;
    while(q--){
        char type; cin >> type;
        if(type == '+'){
            int a, b; char c; cin >> a >> b >> c;
            mp[{a, b}] = c;
            if(mp.count({b, a})) cnttot++;
            if(mp.count({b, a}) && mp[{b, a}] == c) cntgood++;
        }
        else if(type == '-'){
            int a, b; cin >> a >> b;
            if(mp.count({b, a})) cnttot--;
            if(mp.count({b, a}) && mp[{b, a}] == mp[{a, b}]) cntgood--;
            mp.erase({a, b});
        }
        else{
            int k; cin >> k; --k;
            if(k%2 == 0) cout << (cnttot?"YES":"NO") << endl;
            else cout << (cntgood?"YES":"NO") << endl;
        }
    }
}
//https://codeforces.com/problemset/problem/558/E
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

template<class T, int SZ> struct LazySeg { // set SZ to a power of 2
	T sum[4*SZ], lazy[4*SZ]; 
	LazySeg() {
		memset(sum,0,sizeof sum);
		memset(lazy,-1,sizeof lazy);
	}
	void push(int ind, int L, int R) { // modify values for current node
		if(lazy[ind] >= 0) sum[ind] = (R-L+1)*lazy[ind]; 
		if (L != R && lazy[ind] >= 0) lazy[2*ind] = lazy[ind], lazy[2*ind+1] = lazy[ind]; 
		lazy[ind] = -1; // pushed lazy to children
	}
	void pull(int ind) { // recalc values for current node
		sum[ind] = sum[2*ind]+sum[2*ind+1]; }
	void build() { for(int i = SZ-1; i>=1; i--) pull(i); }
	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc; 
			push(ind,L,R); return;
		}
		int M = (L+R)/2;
		upd(lo,hi,inc,2*ind,L,M); upd(lo,hi,inc,2*ind+1,M+1,R);
		pull(ind);
	}
	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ-1) {
		push(ind,L,R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L+R)/2;
		return qsum(lo,hi,2*ind,L,M)+qsum(lo,hi,2*ind+1,M+1,R);
	}
};

vector<LazySeg<int, MAXN>> chars(26, LazySeg<int, MAXN>());

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, q; cin >> n >> q;
    string s; cin >> s;
    // LazySeg<int, 1> lol = LazySeg<int, 1>();
    // lol.upd(0, 0, 1);
    // cout << lol.sum[1] << endl;
    // cout << lol.qsum(0, 0) << endl;

    for(int i = 0; i<n; i++){
        chars[s[i]-'a'].upd(i, i, 1);
    }
    //cout << chars[0].qsum(0, 0) << endl;
    
    while(q--){
        int a, b, c; cin >> a >> b >> c;
        --a; --b;
        if(c == 1){
            int stuff[26];
            for(int i = 0; i<26; i++) stuff[i] = chars[i].qsum(a, b);
            int cur = a;
            for(int i = 0; i<26; i++){
                chars[i].upd(cur, cur+stuff[i]-1, 1);
                chars[i].upd(cur+stuff[i], b, 0);
                chars[i].upd(a, cur-1, 0);
                cur += stuff[i];
            }
            // int check = 6;
            // for(int i = 0; i<n; i++) cout << chars[check].qsum(i, i);
            // cout << endl;
        }
        else{
            int stuff[26] = {0};
            for(int i = 0; i<26; i++) stuff[i] = chars[i].qsum(a, b);
            int cur = b;
            for(int i = 0; i<26; i++){
                chars[i].upd(cur-stuff[i]+1, cur, 1);
                chars[i].upd(a, cur-stuff[i], 0);
                chars[i].upd(cur+1, b, 0);
                cur -= stuff[i];
            }
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<26; j++) if(chars[j].qsum(i, i)) cout << (char)(j+'a');
    }
    cout << endl;
}
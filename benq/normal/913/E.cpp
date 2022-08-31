#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

const int MOD = 1000000007;

bool CMP (const string& a, const string& b) {
    if (sz(a) != sz(b)) return sz(a) < sz(b);
    return a < b;
}

struct cmp {
    bool operator()(const pair<string,string>& a, const pair<string,string>& b) {
        if (a.f != b.f) return !CMP(a.f,b.f);
        return a.s>b.s;
    }
};

    
int n;
map<string,string> ans;
priority_queue<pair<string,string>,vector<pair<string,string>>,cmp> todo;

string NOT(string x) {
    F0R(i,8) {
        if (x[i] == '0') x[i] = '1';
        else x[i] = '0';
    }
    return x;
}

string AND(string x, string y) {
    string z;
    F0R(i,8) {
        if (x[i] == '1' && y[i] == '1') z += '1';
        else z += '0';
    }
	if (x[8] == '1' || y[8] == '1') z += '1';
	else z += '0';
	
    return z;
}

string OR(string x, string y) {
    string z;
    F0R(i,8) {
        if (x[i] == '1' || y[i] == '1') z += '1';
        else z += '0';
    }
    z += '1';
    return z;
}

void tri(string a, string b) {
    if (!ans.count(b) || CMP(a,ans[b])) {
        ans[b] = a;
        todo.push({a,b});
    } 
}

void processnot(string a, string b) {
    string A;
    if (sz(a) == 1) A = "!"+a;
    else A = "!("+a+")";
    
    tri(A,NOT(b));
}

void processand(string a, string b) {
    string A;
    if (b[8] == '0') A = a;
    else A = "("+a+")";
    
    auto z = ans;
    for (auto c: z) {
        string C;
        if (c.f[8] == '0') C = c.s;
        else C = "("+c.s+")";
        tri(C+"&"+A,AND(b,c.f));
        tri(A+"&"+C,AND(b,c.f));
    }
}

void processor(string a, string b) {
    auto z = ans;
    for (auto c: z) {
        tri(c.s+"|"+a,OR(b,c.f));
        tri(a+"|"+c.s,OR(b,c.f));
    }
}

void gen() {
    ans["000011110"] = "x";
    ans["001100110"] = "y";
    ans["010101010"] = "z";
    todo.push({"x","000011110"}), todo.push({"y","001100110"}), todo.push({"z","010101010"});
    
    while (sz(todo)) {
        auto a = todo.top(); todo.pop();
        if (ans[a.s] != a.f) continue;
        processnot(a.f,a.s);
        processand(a.f,a.s);
        processor(a.f,a.s);
    }
}

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	gen();
	cin >> n;
	
	F0R(i,n) {
	    string x; cin >> x;
	    string z = ans[x+'0'], Z = ans[x+'1'];
	    if (sz(z) == 0) cout << Z << "\n";
	    else if (sz(Z) == 0) cout << z << "\n";
	    else {
	    	if (CMP(z,Z)) cout << z << "\n";
	    	else cout << Z << "\n";
	    }
	}
}

// read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!read!
// ll vs. int!
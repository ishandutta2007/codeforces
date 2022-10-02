#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

// Returns the time elapsed in nanoseconds from 1 January 1970, at 00:00:00.
LL get_time() {
    return chrono::duration_cast<chrono::nanoseconds>(
        chrono::steady_clock::now().time_since_epoch())
        .count();
}

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

const int MAXN = 1<<20;
int ff[2*MAXN];
int memo[2*MAXN];

void propagate(int v) {
	if (memo[v] == 0) return;
	memo[2*v] += memo[v];
	memo[2*v+1] += memo[v];
	ff[2*v] += memo[v];
	ff[2*v+1] += memo[v];
	memo[v] = 0;
}

void update(int v, int l, int r, int a, int b, int z) {
	if (r < a or b < l) return;
	if (a <= l and r <= b) {
		ff[v] += z;
		memo[v] += z;
		return;
	}
	propagate(v);
	int m = (l+r)/2;
	update(2*v, l, m, a, b, z);
	update(2*v+1, m+1, r, a, b, z);
	ff[v] = min(ff[2*v], ff[2*v+1]);
}

struct Interval {
	int l, r;
	LL w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in problems with online queries!
    
    int n, m;
    cin >> n >> m;
    vector<Interval> vec(n);
    for (int i = 0; i < n; i++) {
		cin >> vec[i].l >> vec[i].r >> vec[i].w;
	}
	sort(vec.begin(), vec.end(), [&](Interval A, Interval B) { return A.w < B.w; });
    
    auto add = [&](int id) {
		update(1, 0, MAXN-1, vec[id].l, vec[id].r-1, 1);
	};
	auto remove = [&](int id) {
		update(1, 0, MAXN-1, vec[id].l, vec[id].r-1, -1);
	};
	
	update(1, 0, MAXN-1, 0, 0, 1);
	update(1, 0, MAXN-1, m, MAXN-1, 1);
    
    LL res = 1e18;
    int it = 0;
    for (int i = 0; i < n; i++) {
		add(i);
		//~ dbg(ff[1]);
		if (ff[1] == 0) continue;
		while (1) {
			remove(it);
			if (ff[1] == 0) {
				add(it);
				break;
			}
			it++;
		}
		//~ dbg(i, it);
		res = min(res, vec[i].w-vec[it].w);
	}
	cout << res << "\n";
}
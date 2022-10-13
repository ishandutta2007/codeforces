/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/

#include <bits/stdc++.h>
using namespace std;

/*******************Debugging defines*************************/

#define ok_dump() cerr<<"OK\n"
#define var_dump(x) cerr<<#x": "<<x<<'\n'
#define arr_dump(x, n) do{cerr<<#x"[]: ";\
     for(int _=0;_<n;++_) cerr<<x[_]<<" ";cerr<<'\n';}while(0)

/*************************************************************/

const int kMaxN = 500000;

int Profit[kMaxN], Time[kMaxN];
int n, w, k;

int total_time, total_profit, economy;

template<typename cmp> 
struct CustomSet {
	int cnt[5005];
	int sz;
	priority_queue<int, vector<int>, cmp> Q;

	void insert(int x) {
		cnt[x] += 1;
		sz += 1;
		if(cnt[x] == 1)
			Q.push(x);
	}
	void erase(int x) {
		cnt[x] -= 1;
		sz -= 1;
	}
	bool has(int x) {
		return cnt[x] > 0;
	}
	void clear() {
		while(!Q.empty()) Q.pop();
		memset(cnt, 0, sizeof(cnt));
		sz = 0;
	}
	int size() {
		return sz;
	}
	int first() {
		while(cnt[Q.top()] == 0) Q.pop();
		return Q.top();
	}
};

CustomSet<greater<int>> GoodSet;
CustomSet<less<int>> BadSet;

void Ins(int x) {
	GoodSet.insert(x);
	economy += x;
	if(GoodSet.size() > w) {
		int y = GoodSet.first();
		economy -= y;
		BadSet.insert(y);
		GoodSet.erase(y);
	}
}
void Ers(int x) {
	if(BadSet.has(x)) 
		BadSet.erase(x);
	else {
		economy -= x;
		GoodSet.erase(x);
		if(BadSet.size() > 0) {
			int y = BadSet.first();
			economy += y;
			GoodSet.insert(y);
			BadSet.erase(y);
		}
	}
}

void Insert(int i) {
	// cerr << "IN: " << i << endl;
	total_time += Time[i];
	total_profit += Profit[i];

	Ins(Time[i] / 2);
}
void Erase(int i) {
	// cerr << "OUT: " << i << endl;
	total_time -= Time[i];
	total_profit -= Profit[i];

	Ers(Time[i] / 2);	
}

bool Check(int need) {
	int i = 1, j = 1;
	total_profit = total_time = economy = 0;
	GoodSet.clear(); BadSet.clear();

	while(i <= n) {
		while(j <= n && total_profit < need)
			Insert(j++);
		if(total_profit >= need && total_time - economy <= k)
			return true;
		Erase(i++);
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// // Comment these lines before submitting
	// freopen("input", "r", stdin);
	// freopen("output", "w", stdout);

	// Start code here

	scanf("%d %d %d", &n, &w, &k);

	for(int i = 1; i <= n; ++i) scanf("%d", Profit + i);
	for(int i = 1; i <= n; ++i) scanf("%d", Time + i);

	// ok_dump();
	// Check(12);
	// return 0;

	int ans = 0;
	for(int step = (1 << 30); step; step /= 2)
		if(Check(ans + step))
			ans += step;
	cout << ans << endl;


	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/
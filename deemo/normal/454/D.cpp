#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<utility>

using namespace std;

typedef long long ll;

const int MAXN = 100 + 4;
const int MAX = 61;

int n, vec[MAXN], sec[MAXN], mini, ans[MAXN], ss[MAXN], sz, sum, size, last[MAXN], gs[MAXN];
ll mark;
bool dd[MAX];
vector<int>	pr;
int gec[MAX];
set<pair<int, int>>	st;


void init(){
	for (int i = 1; i < MAX; i++){
		int cnt = 0;
		for (int j = 1; j <= i; j++)
			if (i % j == 0){
				cnt++;
				if (dd[j])	gec[i] |= ll(1) << j;
			}
		if (cnt == 2){
			pr.push_back(i);
			dd[i] = 1;
			gec[i] |= ll(1) << i;
		}
	}
}

void gen(int ind = 0){
	if (sz > n)	return;
	{
		int ret = sum, t = n;
		copy(ss, ss + sz, gs);
		sort(gs, gs + sz);
		for (int i = sz - 1; i >= 0; i--){
			ret -= (sec[--t] - 1);
			ret += abs(sec[t] - gs[i]);
		}

		if (ret < mini){
			copy(gs, gs + sz, ans);
			size = sz;
			mini = ret;
		}
	}

	for (int i = ind; i < pr.size(); i++){
		int x = pr[i];

		for (int j = x; j < MAX; j += x){
			if (mark & gec[j])	continue;

			mark ^= gec[j];
			ss[sz++] = j;
			gen(i + 1);
			sz--;
			mark ^= gec[j];
		}
	}
}

int main(){
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> vec[i];
		sum += vec[i] - 1;
	}
	mini = sum;
	copy(vec, vec + n, sec);
	sort(sec, sec + n);
	fill(ans, ans + n, 1);	size = n;

	init();
	gen();

	for (int i = size; i < n; i++)	ans[i] = 1;
	for (int i = 0; i < n; i++)
		st.insert({vec[i], i});
	sort(ans, ans + n);
	for (int i = n - 1; i >= 0; i--){
		int x = ans[i];
		set<pair<int, int>>::iterator it = st.end();	it--;
		last[it->second] = x;
		st.erase(it);
	}
	for (int i = 0; i < n; i++)
		cout << last[i] << " ";
	cout << endl;
	return	0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cassert>
#include<deque>

using namespace std;

const int MAXN = 1e3 + 10;

int n, c[MAXN], cc[MAXN], mx;
deque<string>	q;
bool fail = 0;
vector<string>	vec[MAXN];

void gen(int cur){
	if (cur > mx)	return;
	
	int rem = cc[cur];
	while (rem && q.size()){
		vec[cur].push_back(q.back());	q.pop_back();
		rem--;
	}

	if (rem){
		fail = 1;
		cout << "NO\n";
		return;
	}

	int tt = q.size();
	for (int i = 0; i < tt && q.size() - tt < MAXN; i++)
		q.push_back(q[i] + '1'), q.push_back(q[i] + '0');
	while (q.size() && q.front().size() == cur)	q.pop_front();
	gen(cur + 1);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;	for (int i = 0; i < n; i++)	cin >> c[i], cc[c[i]]++, mx = max(mx, c[i]);
	q.push_back("0");
	q.push_back("1");
	gen(1);
	if (!fail){
		cout << "YES\n";
		for (int i = 0; i < n; i++){
			assert(vec[c[i]].size());
			cout << vec[c[i]].back() << "\n", vec[c[i]].pop_back();
		}
	}
	return 0;
}
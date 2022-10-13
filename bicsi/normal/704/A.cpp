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

const int kMaxN = 300000;

vector<int> Have[kMaxN];
vector<int> Del;

int main() {

	int n, q;
	scanf("%d %d", &n, &q);

	int cnt = 0, last = 0;
	while(q--) {
		int t, x;
		scanf("%d %d", &t, &x);

		if(t == 1) {
			Have[x].push_back(Del.size());
			Del.push_back(0);
			cnt += 1;
		}

		if(t == 2) {
			for(auto app : Have[x]) {
				if(Del[app]) continue;
				Del[app] = 1;
				cnt -= 1;
			}
			Have[x].clear();
		}

		if(t == 3) {
			for(int i = last; i < x; ++i) {
				if(Del[i]) continue;
				Del[i] = 1;
				cnt -= 1;
			}
			last = max(last, x);
		}

		printf("%d\n", cnt);
	}

	return 0;
}

/*************************************************************\
~*********************ENJOY THE SILENCE***********************~
\*************************************************************/
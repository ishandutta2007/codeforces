#include<cstdio>
#include<algorithm>
#include<set>
#include<utility>
#include<map>

using namespace std;

const int MAXQ = 1e5 + 10;
const int MAXN = 1e9 + 10;

int n, q;
set<int>	st;
set<pair<int, int>>	seg;
map<int, int>	mp, fen;

int get(int v){
	int ret = 0;
	for (; v; v-=v&-v)
		ret += fen[v];
	return ret;
}

void add(int v, int val){
	for (; v < MAXN; v += v&-v)
		fen[v] += val;
}

int main(){
	scanf("%d %d", &n, &q);
	seg.insert({n, 1});
	st.insert(0);
	st.insert(n+1);

	while (q--){
		int id;	scanf("%d", &id);
		if (id == 0){
			int l, r;	scanf("%d %d", &l, &r);
			printf("%d\n", get(r) - get(l - 1));
		}
		else{
			if (mp.count(id)){
				int pos = mp[id], sz = 1, l = pos;
				st.erase(pos);
				
				auto it = st.lower_bound(pos);
				if (it != st.end()){
					sz += *it - pos - 1;
					seg.erase({*it - pos - 1, pos + 1});
				}
				if (it != st.begin()){
					it--;
					sz += pos - *it - 1;
					l = *it + 1;
					seg.erase({pos - *it - 1, *it + 1});
				}

				add(pos, -1);
				mp.erase(id);
				seg.insert({sz, l});
			}
			else{
				auto it = seg.end();	it--;
				int sz = it->first, pos = it->second;
				seg.erase(it);
				int ret = pos + sz/2;
				add(ret, 1);
				mp[id] = ret;
				if (ret - pos)
					seg.insert({ret - pos, pos});
				sz -= (ret - pos + 1);
				if (sz)
					seg.insert({sz, ret + 1});
				st.insert(ret);
			}
		}	
	}
	return 0;
}
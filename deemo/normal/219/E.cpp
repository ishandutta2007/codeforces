#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>

using namespace std;

#define F first
#define S second

const int MAXN = 2e5 + 10;
const int XX = 1e6 + 10;
const int INF = 1e8;

int n, q;
int mp[XX];
set<int>	st;
set<pair<int, int>>	ff;

int main(){
	scanf("%d %d", &n, &q);
	while (q--){
		int type, id;	scanf("%d %d", &type, &id);
		if (type - 1){
			id = mp[id];
			int prv, nxt;
			auto it = st.upper_bound(id);
			nxt = (it==st.end()?n:*it);	it--;
			prv = (it==st.begin()?-1:*(--it));
			ff.erase({nxt - id - 1, -(id + 1)});
			ff.erase({id - prv - 1, -(prv + 1)});
			if (prv != -1 && nxt != n)
				ff.insert({nxt - prv - 1, -(prv + 1)});
			st.erase(id);
		}
		else{
			auto it = ff.end();	
			int mn = 0;
			if (ff.size()){
				it--;
				mn = -it->S + (it->F - 1)/2;
				if (it->F % 2 == 0){
					int temp = it->F;
					it = ff.lower_bound({it->F - 1, 1});
					if (it != ff.begin()){

						it--;
						if (it != ff.end() && it->F == temp - 1)
							mn = min(mn, -it->S + (it->F - 1)/ 2);
					}
				}
			}
			if (st.empty())	mn = 0;
			else{
				int prv, nxt;
				auto it2 = st.upper_bound(mn);
				nxt = (it2==st.end()?INF:*it2);	
				prv = (it2==st.begin()?-INF:*(--it2));

				int dif = min(mn - prv, nxt - mn);
				if (st.count(0) == 0 && *st.begin() >= dif)	mn = 0, dif = *st.begin();
				if (st.count(n - 1) == 0){
					auto it3 = st.end();	it3--;
					if (n - *it3 - 1 > dif)	mn = n - 1;
				}
			}
			printf("%d\n", mn + 1);

			int prv, nxt;
			auto it2 = st.upper_bound(mn);
			nxt = (it2==st.end()?n:*it2);
			prv = (it2==st.begin()?-1:*(--it2));
			ff.erase({nxt - prv - 1, -(prv + 1)});
			if (prv != -1)
				ff.insert({mn - prv - 1, -(prv + 1)});
			if (nxt != n)
				ff.insert({nxt - mn - 1, -(mn + 1)});
			mp[id] = mn;
			st.insert(mn);
		}
	}
	return 0;
}
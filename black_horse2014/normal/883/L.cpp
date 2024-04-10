#include <bits/stdc++.h>

using namespace std;


struct car {
	
	long long id, des;
	long long arr;
	
 	car(long long id, long long des, long long arr) : id(id), des(des), arr(arr) {}
 	
	bool operator < (const car &rhs) const {
		if (arr != rhs.arr) return arr < rhs.arr;
		if (des != rhs.des) return des < rhs.des;
		return id < rhs.id;
	}
	bool operator == (const car &rhs) const {
		return arr == rhs.arr && des == rhs.des && id == rhs.id;
	}
	
};

struct wat {
	
	long long id, des;
	long long arr;
	
 	wat(long long id, long long des, long long arr) : id(id), des(des), arr(arr) {}
 	
	bool operator < (const wat &rhs) const {
		if (des != rhs.des) return des < rhs.des;
		if (arr != rhs.arr) return arr < rhs.arr;
		return id < rhs.id;
	}
	bool operator == (const wat &rhs) const {
		return arr == rhs.arr && des == rhs.des && id == rhs.id;
	}
};

const long long INF = 1e18;
set<wat> E;
set<car> S;
set<wat> :: iterator itw;
set<car> :: iterator it;
int n, k, m;
vector<car> V;
int main() {
	
	//freopen("in.txt", "r", stdin);
	
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 1; i <= k; i++) {
		
		int x; scanf("%d", &x);
		E.insert(wat(i, x, 0));
	}
	
	while (m--) {
		
		long long a, b, t;
		scanf("%lld%lld%lld", &t, &a, &b);
		V.clear();
		it = S.begin();
		while (it != S.end()) {
			
			if (it->arr <= t) {
				V.push_back(*it);
				
			}
			else break;
			it++;
		}
		
		for (int i = 0; i < V.size(); i++) {
			S.erase(V[i]);
			E.insert(wat(V[i].id, V[i].des, V[i].arr));
		}
		
		if (!E.empty()) {
			itw = E.lower_bound(wat(0, a, 0));
			
			long long dev = (itw == E.end() ? INF : abs(itw->des - a));
			if (itw != E.begin()) {
				itw--;
				dev = min(dev, a - itw->des);
				itw++;
			}
			wat pik1(0, a, INF), pik2(0, a, INF);
			long long cur = a - dev;
			itw = E.lower_bound(wat(0, cur, 0));
			if (itw != E.end() && itw->des == cur) {
				pik1 = *itw;
			}
			cur = a + dev;
			itw = E.lower_bound(wat(0, cur, 0));
			if (itw != E.end() && itw->des == cur) {
				pik2 = *itw;
			}
			if (pik1.arr < pik2.arr || pik1.arr == pik2.arr && pik1.id < pik2.id) pik2 = pik1;
			
			printf("%lld %lld\n", pik2.id, abs(pik2.des - a));
			E.erase(pik2);
			S.insert(car(pik2.id, b, abs(b - a) + t + abs(a - pik2.des)));
			continue;
		}
		
		it = S.begin();
		long long dd = it->arr;
		it = S.lower_bound(car(0, a, dd));
		long long dev = ((it == S.end() || it->arr != dd) ? INF : abs(it->des - a));
		if (it != S.begin()) {
			it--;
			if (it->arr == dd) dev = min(dev, a - it->des);
		}
		car pik1(0, a, INF), pik2(0, a, INF);
		
		long long cur = a - dev;
		it = S.lower_bound(car(0, cur, dd));
		if (it != S.end() && it->des == cur && it->arr == dd) {
			pik1 = *it;
		}
		cur = a + dev;
		it = S.lower_bound(car(0, cur, dd));
		if (it != S.end() && it->des == cur && it->arr == dd) {
			pik2 = *it;
		}
		if (pik1.arr < pik2.arr || pik1.arr == pik2.arr && pik1.id < pik2.id) pik2 = pik1;
		
		S.erase(pik2);
		S.insert(car(pik2.id, b, dd + abs(b - a) + abs(pik2.des - a)));
		printf("%lld %lld\n", pik2.id, dd - t + abs(pik2.des - a));
		
	}
	return 0;
}
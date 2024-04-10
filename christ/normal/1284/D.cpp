#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using ppiipii = pair<pii,pii>;
const int MN = 6e5+2;
#define all(x) (x).begin(),(x).end()
vector<int> xs;
void getx (int &x) {x = lower_bound(all(xs),x)-xs.begin()+1;}
struct Event {
	int x,bl,br;
};
vector<Event> ed[MN],st[MN];
int lbit[MN], rbit[MN];
void inc (int *bit, int i) {
	for (;i<MN;i+=i&-i)
		++bit[i];
}
void dec (int *bit, int i) {
	for(;i<MN;i+=i&-i)
		--bit[i];
}
int query (int *bit, int i) {
	int ret = 0;
	for(;i;i^=i&-i)
		ret += bit[i];
	return ret;
}
int main () {
	int n;
	scanf ("%d",&n);
	vector<ppiipii> segs(n);
	for(auto &au : segs) {
		scanf ("%d %d %d %d",&au.first.first,&au.first.second,&au.second.first,&au.second.second);
		xs.push_back(au.first.first); xs.push_back(au.second.first); xs.push_back(au.first.second); xs.push_back(au.second.second);
	}
	sort(all(xs)); assert(xs.size() < MN);
	for (auto &au : segs) {
		getx(au.first.first); getx(au.second.first);
		getx(au.first.second); getx(au.second.second);
		st[au.first.first].push_back({au.first.second,au.second.first,au.second.second});
		ed[au.first.second].push_back({au.first.first,au.second.first,au.second.second});
	}
	int ree = xs.size();
	for (int i = 1; i <= ree; i++) {
		for (Event e : st[i]) {
			if (query(rbit,e.bl-1)>0||query(lbit,MN-1)-query(lbit,e.br)>0) {
				return !printf ("NO\n");
			}
			inc(lbit,e.bl); inc(rbit,e.br);
		}
		for (Event e : ed[i]) {
			dec(lbit,e.bl); dec(rbit,e.br);
		}
	}
	for (int i = 0; i < MN; i++) {
		st[i].clear(); ed[i].clear();
	}
	memset(lbit,0,sizeof lbit); memset(rbit,0,sizeof rbit);
	for (auto &au : segs) {
		st[au.second.first].push_back({au.second.second,au.first.first,au.first.second});
		ed[au.second.second].push_back({au.second.first,au.first.first,au.first.second});
	}
	for (int i = 1; i <= ree; i++) {
		for (Event e : st[i]) {
			if (query(rbit,e.bl-1)>0||query(lbit,MN-1)-query(lbit,e.br)>0) {
				return !printf ("NO\n");
			}
			inc(lbit,e.bl); inc(rbit,e.br);
		}
		for (Event e : ed[i]) {
			dec(lbit,e.bl); dec(rbit,e.br);
		}
	}
	printf ("YES\n");
	return 0;
}
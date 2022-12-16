#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> par, cnt, nxt, lst;

void SETUP(int sz) {
	par = vector<int>(sz, -1);
	cnt = vector<int>(sz, 1);
	nxt = vector<int>(sz, -1);
	lst = vector<int>(sz, -2);
}

int FIND(int a) {
	return (par[a] == -1?a:par[a]=FIND(par[a]));
}
int NEXT(int a) {
	return (nxt[a] == -1?a:nxt[a]=NEXT(nxt[a]));
}
int LAST(int a) {
	return (lst[a] == -2 ?a:(a==-1?a:lst[a]=LAST(lst[a])));
}
int REMOVE(int a) {
	nxt[a] = a+1;
	lst[a] = a-1;
}
int UNION(int l, int r) {
	cnt[FIND(l)] += cnt[FIND(r)];
	cnt[FIND(r)] = 0;
	par[FIND(r)] = FIND(l);
}

struct group {
	int first, second;
	bool operator< (const group& o) const {
		if(first == o.first) return second > o.second;
		return first < o.first;
	}
};

inline char get() {
	static char buf[100000], *S=buf, *T=buf;
	if(S==T) {
		T=(S=buf)+fread(buf, 1, 100000, stdin);
		if(S==T) return EOF;
	}
	return *S++;
}
inline void read(int& x){
	static char c; x=0;
	for(c=get();c < '0' || c > '9';c=get());
	for(;c >='0' && c <='9';c=get()) x = (int) c - '0' + x*10;
}


int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	int N;
	read(N);
	SETUP(N+1);
	vector<int> a(N);
	for(auto& ii : a)
		read(ii);
	set<group> groups;
	for(int i=0;i<N-1;++i) {
		if(a[i] == a[i+1])
			UNION(i, i+1);
	}
	for(int i=0;i<N;++i) {
		if(cnt[i] != 0)
			groups.insert({cnt[i], i});
	}
	int amt = 0;
	while(NEXT(0) != N) {
		++ amt;
		group g = *groups.rbegin();
		groups.erase(--groups.end());

		int l = g.second;
		for(int i=0;i<g.first;++i, l=NEXT(l))
			REMOVE(l);

		if(LAST(g.second) == -1) continue;

		if(NEXT(0) != N && a[LAST(g.second)] == a[l]) {
			groups.erase({cnt[FIND(LAST(g.second))], FIND(LAST(g.second))});
			groups.erase({cnt[l], l});
			UNION(LAST(g.second), l);
			groups.insert({cnt[FIND(LAST(g.second))], FIND(LAST(g.second))});
		}
	}
	cout << amt << endl;
	
	return 0;
}
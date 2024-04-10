#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pdd;
typedef complex<ld> pt;

struct itcomp {
	bool operator() (const list<int>::iterator& a, const list<int>::iterator& b) {
		return (*a) < (*b);
	}
};


typedef set<list<int>::iterator, itcomp> Slit;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	string s;
	cin >> s;
	list<int> l;
	for(int i=0;i<s.length();++i)
		l.push_back(i);
	Slit pos, posa;
	for( auto it  = l.begin(); it != l.end(); ++it) {	
		char here = s.at(*it);
		char aft = here;
		char prev = here;
		if(it != l.begin()) {
			--it;
			prev = s.at(*it);
			++it;
		}
		++it;
		if(it != l.end())
			aft = s.at(*it);
		--it;

		if(here != aft || here != prev)
			pos.insert(it);
	}

	int cnt = 0;
	while(pos.size() > 0) {
		posa = pos;
		pos = Slit();
		Slit removal;
		
		for( auto it : posa ) {
			char here = s.at(*it);
			char aft = here;
			char prev = here;
			if(it != l.begin()) {
				--it;
				prev = s.at(*it);
				++it;
			}
			++it;
			if(it != l.end())
				aft = s.at(*it);
			--it;
			
			if(here != aft || here!= prev) {
				removal.insert(it);
				if(it != l.begin()) {
				--it;
					pos.insert(it);
				}
				++it; ++it;
				if(it != l.end())
					pos.insert(it);
				--it;
			}
		}

		bool change = false;
		for( auto it : removal ) {
			pos.erase(it);
			l.erase(it);
			change = true;
		}
		if(change)
			++cnt;

		//cerr; for( auto it : l )
			//cerr << s.at(it);
		//cerr << endl;

	}
	
	cout << cnt << endl;

	return 0;
}
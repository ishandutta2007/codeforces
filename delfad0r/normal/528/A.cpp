#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int W, H, N;

set< int > Hranges, Vranges;
map< int, int > Hlengths, Vlengths;

void cut(set< int > & ranges, map< int, int > & lengths, int pos) {
	auto it = ranges.insert(pos).first;
	auto it1 = it, it2 = it;
	--it1; ++it2;
	if(--lengths[*it2 - *it1] == 0) lengths.erase(*it2 - *it1);
	++lengths[pos - *it1];
	++lengths[*it2 - pos];
}

int main() {
	scanf("%d%d%d\n", &W, &H, &N);
	Hranges.insert(0);
	Hranges.insert(H);
	++Hlengths[H];
	Vranges.insert(0);
	Vranges.insert(W);
	++Vlengths[W];
	while(N--) {
		char t;
		int pos;
		scanf("%c%d\n", &t, &pos);
		if(t == 'H') cut(Hranges, Hlengths, pos);
		else cut(Vranges, Vlengths, pos);
		printf("%I64d\n", ll((--Vlengths.end())->first) * ll((--Hlengths.end())->first));
	}
}
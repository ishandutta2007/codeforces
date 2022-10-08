#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
typedef pair<int,int> pii;

pii D[100000];
vector <pii> ANS;
set <pii> real_ANS;
int main() {
	int i, N, st = 0;
	scanf("%d", &N);
	for(i = 0; i < N; i++) {
		scanf("%d %d", &D[i].first, &D[i].second);
		if(D[i].first == 1) {
			ANS.push_back(make_pair(i, D[i].second));
		}
	}
	while(st < ANS.size()) {
		int t1 = ANS[st].first;
		int t2 = ANS[st].second;
		if(t1>t2) swap(t1,t2);
		if(real_ANS.find(make_pair(t1,t2)) != real_ANS.end()) {
			st++;
			continue;
		}
		real_ANS.insert(make_pair(t1,t2));
		D[t1].first--;
		D[t1].second ^= t2;
		D[t2].first--;
		D[t2].second ^= t1;
		
		if(D[t1].first == 1) ANS.push_back(make_pair(t1, D[t1].second));
		if(D[t2].first == 1) ANS.push_back(make_pair(t2, D[t2].second));
		st++;
	}

	printf("%d\n", real_ANS.size());
	for(set <pii>::iterator it = real_ANS.begin(); it != real_ANS.end(); it++) {
		printf("%d %d\n", it->first, it->second);
	}
	return 0;
}
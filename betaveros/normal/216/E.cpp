#include <cstdio>
#include <map>
#include <list>
using namespace std;

typedef long long int lli;

map<int, list<int> > submodmap;
map<int, bool> checkedmap;

int basemod;
int lucky;
int len;
int digits[100000];
lli subsums[100001];

void readDigits(){
	int base;
	scanf("%d %d %d", &base, &lucky, &len);
	basemod = base - 1;
	for (int i = 0; i < len; i++){
		scanf("%d", &digits[i]);
	}
}

void computeSubsums(){
	lli subsum = 0;
	for (int i = 0; i < len; i++){
		subsums[i] = subsum;
		subsum += digits[i];

		submodmap[(int) (subsums[i] % basemod)].push_back(i);
	}
	subsums[len] = subsum;
	submodmap[(int) (subsums[len] % basemod)].push_back(len);
}

lli countLuckySubstrings(){
	lli count = 0;
	if (lucky == 0) {// corner case
		// lesson: never delete code you think might be useful
		int s = 0;
		while (s < len && digits[s] != 0) s++;
		while (s < len){
			// now digits[s] == 0
			lli zeroes = 0;
			while (s < len && digits[s] == 0) { s++; zeroes++; }
			count += (zeroes * (zeroes + 1)) / 2;
			while (s < len && digits[s] != 0) s++;
		}
		return count;
	}
	computeSubsums();
	for (int s = 0; s < len; s++){
		int origmod = (subsums[s] % basemod);
		if (checkedmap[origmod]) continue;
		checkedmap[origmod] = true;
		list<int> origis = submodmap[ (int) (origmod) ];
		lli targetmod = subsums[s];
		targetmod += lucky; // must not overflow
		targetmod %= basemod;
		list<int> targetis = submodmap[ (int) (targetmod) ];
		list<int>::iterator oi = origis.begin();
		list<int>::iterator ti = targetis.begin();
		int titail = targetis.size();
		while (oi != origis.end()){
			if (ti == targetis.end()) break;
			while (ti != targetis.end() && 
				(subsums[*ti] <= subsums[*oi])){
				ti++;
				titail--;
				if (ti == targetis.end()) break;
			}
			count += titail;
			oi++;
		}
	}
	return count;
}


int main(){
	readDigits();
#ifdef ONLINE_JUDGE
	printf("%I64d", countLuckySubstrings());
#else
	printf("%lld", countLuckySubstrings());
#endif
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 111111;

int k, n, m;
int a[N];

struct Item {
	int type, val, id;
	Item() {}
	Item(int type, int val, int id) : type(type), val(val), id(id) {}
};

struct Frac {
	long long num, den;
	int id;
	Frac() {}
	Frac(long long num, long long den, int id) : den(den), num(num), id(id) {}
	friend inline bool operator <(const Frac &a, const Frac &b) {
		Frac aa = a, bb = b;
		aa.num -= aa.den;
		bb.num -= bb.den;
		return aa.num * bb.den > bb.num * aa.den;
	}
};

vector<Item> modifies[N];
vector<Frac> frac;
int record[N];


bool compare(const Item &a, const Item &b) {
	if (a.type == 3 || b.type == 3) {
		return a.type < b.type;
	}
	return a.val > b.val;
}

bool byType(int a, int b) {
	return record[a] < record[b];
}

int main() {
	scanf("%d %d %d", &k, &n, &m);
	for(int i = 1; i <= k; i++) {
		scanf("%d", &a[i]);
	}
	for(int i = 1; i <= n; i++) {
		int type, which, val;
		scanf("%d %d %d", &type, &which, &val);
		if (type == 1) {
			val -= a[which];
		}
		modifies[which].push_back(Item(type, val, i));
		record[i] = type;
	}
	for(int i = 1; i <= k; i++) {
		sort(modifies[i].begin(), modifies[i].end(), compare);
		bool assigned = false;
		long long origin = a[i];
		for(int j = 0; j < (int)modifies[i].size(); j++) {
			Item it = modifies[i][j];
			if (it.type == 1) {
				if (assigned) {
					continue;
				} else {
					assigned = true;
					if (it.val > 0) {
						frac.push_back(Frac(it.val + origin, origin, it.id));
						origin += it.val;
					}
				}
			} else if (it.type == 2) {
				frac.push_back(Frac(it.val + origin, origin, it.id));
				origin += it.val;
			} else {
				frac.push_back(Frac(it.val, 1, it.id));
			}
		}
	}
	sort(frac.begin(), frac.end());
	vector<int> answers;
	for(int i = 0; i < m && i < (int)frac.size(); i++) {
		answers.push_back(frac[i].id);
	}
	sort(answers.begin(), answers.end(), byType);
	printf("%d\n", (int)answers.size());
	for(int i = 0; i < (int)answers.size(); i++) {
		printf("%d%c", answers[i], " \n"[i == (int)answers.size() - 1]);
	}
	return 0;
}
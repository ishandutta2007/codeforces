#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define BIG 200004
// manually tested, upper bd of divisible pairs
// owait, we don't need it because vectors
#define DIVPAIRS 2500000
// #define debug(code) code

int perm[BIG];
int invperm[BIG];
struct query {
	query(int l, int r, int o): left(l), right(r), order(o) {}
	int left;
	int right;
	int order;
	bool operator<(const query& other) const {
		if (right < other.right) return true;
		if (right > other.right) return false;
		return left < other.left;
	}
};
struct divp {
	divp(int a = -1, int b = -1) {
		if (a > b) {i2 = a; i1 = b;}
		else {i1 = a; i2 = b;}
	}
	int i1, i2;
	bool operator<(const divp& other) const {
		if (i2 < other.i2) return true;
		if (i2 > other.i2) return false;
		return i1 < other.i1;
	}
};
vector<divp> divps;
vector<query> queries;
vector<int> answers;
int permSize, nQueries;

void readInput() {
	cin >> permSize >> nQueries;
	for (int i = 1; i <= permSize; i++) {
		cin >> perm[i];
		invperm[perm[i]] = i;
	}
	for (int i = 0; i < nQueries; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back(query(l, r, i));
	}
	answers.assign(nQueries, -1);
}

void listDivs(){
	for (int d1 = 1; d1 <= permSize; d1++){
		for (int d2 = d1; d2 <= permSize; d2 += d1){
			divps.push_back(divp(invperm[d1], invperm[d2]));
		}
	}
}
int computeAnswer(){
	vector<int> fw(permSize + 4, 0);
	// the fenwick tree records # of pairs by left index 
	// for each right index rix
	// 1. add all pairs ending in rix to fenwick tree
	// 2. answer all queries with rix
	
	vector<divp>::iterator dit = divps.begin();
	vector<query>::iterator qit = queries.begin();
	int totalDivs = 0;

	for (int rix = 1; rix <= permSize; rix++){
		// 1
		while (dit->i2 == rix) {
			int i1 = dit->i1;
			// adding to fenwick
			while (i1 <= permSize){
				fw[i1]++;
				i1 += i1 & -i1;
			}
			// also add to total
			totalDivs++;
			dit++;
		}
		// 2
		while (qit->right == rix) {
			int left = qit->left - 1; // subtotal excluding query
			int ans = totalDivs;
			while (left > 0){
				ans -= fw[left];
				left -= left & -left;
			}
			// debug(cout << "Answering " << qit->order << endl);
			answers[qit->order] = ans;
			qit++;
		}
	}
}
void printAnswer(){
	for (int i = 0; i < nQueries; i++)
		cout << answers[i] << endl;
}

int main() {
	readInput();
	listDivs();
	sort(divps.begin(), divps.end());
	sort(queries.begin(), queries.end());
	computeAnswer();
	printAnswer();
	return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n; // # of threads
vector<vector<int> > bridges;


void readInput(){
	scanf("%d", &n);
	bridges.reserve(n);
	for (int i = 0; i < n; i++){
		vector<int> sector;
		int c;
		scanf(" %d", &c);
		sector.reserve(c);
		for (int j = 0; j < c; j++){
			int x;
			scanf(" %d", &x);
			sector.push_back(x);
		}
		sort(sector.begin(), sector.end());
		bridges.push_back(sector);
	}
}

int countUnstableCells(){
	int count = 0;
	for (int i = 0; i < n; i++){
		vector<int> sector = bridges[i];
		vector<int> s1 = bridges[(i > 0) ? (i-1) : (n-1)];
		vector<int> s2 = bridges[(i < n-1) ? (i+1) : 0];
		
		vector<int>::iterator it = sector.begin();
		vector<int>::iterator i1 = s1.begin();
		vector<int>::iterator i2 = s2.begin();
		
		if (it == sector.end()) continue;
		int lower = *it;
		it++;
		int upper;
		while (it != sector.end()){
			int force1 = 0;
			int force2 = 0;
			upper = *it;
			while (i1 != s1.end() && *i1 < lower) i1++;
			while (i1 != s1.end() && *i1 < upper) {i1++; force1++;}

			while (i2 != s2.end() && *i2 < lower) i2++;
			while (i2 != s2.end() && *i2 < upper) {i2++; force2++;}

			if (force1 != force2) count++;
			// next
			lower = upper;
			it++;
		}
	}
	return count;
}

int main(){
	readInput();
	printf("%d", countUnstableCells());
}
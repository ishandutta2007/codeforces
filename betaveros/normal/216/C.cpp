#include <cstdio>
#include <vector>
using namespace std;

int workers[2000];
bool keyGiven[2000];

int work;
int rest;
int period;
int load;

vector<int> hireDates;


void readInput(){
	scanf("%d %d %d", &work, &rest, &load);
	period = work + rest;
}

void reset(){
	for (int i = 0; i < period; i++) {
		workers[i] = 0;
		keyGiven[i] = 0;
	}
}

void findSolution(){
	reset();
	for (int i = 0; i < period; i++){
		while (workers[i] < load || !keyGiven[i]) {
			hireDates.push_back(i);
			for (int j = 0; j < work; j++){
				if (i + j >= period) break;
				workers[i + j]++;
				if (j < work - 1) keyGiven[i + j]++;
			}
		}
	}
}


int main(){
	readInput();
	findSolution();
	printf("%d\n", (int) hireDates.size());
	vector<int>::iterator it;
	bool first = true;
	for (it = hireDates.begin(); it != hireDates.end(); it++){
		if (first) first = false;
		else printf(" ");

		printf("%d", *it + 1); // zero -> one-index
	}
}
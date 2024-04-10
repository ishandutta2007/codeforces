#include <iostream>
#define NDEBUG
#include <cassert>
#define MAXN 500004
using namespace std;
char road[MAXN];
int surplus[MAXN];
int n, t;
int houseN, shopN, lastHouse;
void computeSurplus(){
	int s = 0;
	houseN = 0;
	shopN = 0;
	for (int i = 0; i < n; i++){
		if (road[i] == 'H') {
			s--;
			houseN++;
			lastHouse = i;
		} else if (road[i] == 'S') {
			s++;
			shopN++;
		}
		surplus[i] = s;
	}
}

int debtRegionStart[MAXN];
int debtRegionEnd[MAXN];
int debtRegionI;

bool tryPrepare(int prepare){
	// first, check for complete candy shortage
	if (prepare + shopN < houseN) return false;
	// printf("tryPrepare: %d\n", prepare);
	debtRegionI = 0;
	
	bool prevInDebt = false;
	int backTs = 0;
	int lastForced;
	for (int i = 0; (i <= lastHouse || prevInDebt); i++){
		bool isInDebt = surplus[i] < -prepare;
		if (isInDebt && !prevInDebt){
			debtRegionStart[debtRegionI] = i;
		} else if (!isInDebt && prevInDebt){
			debtRegionEnd[debtRegionI] = i;
			backTs += (debtRegionEnd[debtRegionI] -
					debtRegionStart[debtRegionI]);
			debtRegionI++;
		}
		prevInDebt = isInDebt;
		lastForced = i; // last square at which visit is forced
	}
	// printf("tryInDebt: %d\n", prevInDebt);
	assert(!prevInDebt);

	int forwardTs = lastForced + 1;
	int baseTs = backTs + forwardTs;
	int totalTs = baseTs + backTs;
	if (totalTs <= t) return true;
	int pos = lastForced;
	for (int dri = debtRegionI - 1; dri >= 0; dri--){
		totalTs += (pos - debtRegionEnd[dri]);
		totalTs -= (debtRegionEnd[dri] - debtRegionStart[dri]);
		pos = debtRegionStart[dri];
		if (totalTs <= t) return true;
	}
	return false;
}

int seekPrepare(int lo, int hi){ // (lo,hi]
	if (hi - lo == 1){
		return hi;
	}
	int mid = (hi + lo) / 2;
	if (tryPrepare(mid)){
		return seekPrepare(lo, mid);
	} else {
		return seekPrepare(mid, hi);
	}

}

void readInput(){
	cin >> n >> t;
	cin.ignore();
	cin.getline(road, MAXN);
}

int main(){
	readInput();
	computeSurplus();
	int prep = seekPrepare(-1, houseN+1);
	if (prep == houseN + 1) prep = -1;
	cout << prep << endl;
}
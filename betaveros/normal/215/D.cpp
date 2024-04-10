#include <cstdio>
#include <cmath>
#define MAXREGIONS 100000
using namespace std;

typedef long long int lli;

int regions; // <= 10^5
int children; // <= 10^6
int tolerance[MAXREGIONS]; // compensate iff children in bus strictly larger
int compensation[MAXREGIONS];
int busCost[MAXREGIONS];

void readInput(){
	scanf("%d %d", &regions, &children);
	for (int i = 0; i < regions; i++){
		int to, tmax;
		scanf("%d %d %d %d",
				&to, &tmax, &(compensation[i]), &(busCost[i]));
		int diff = tmax - to;
		tolerance[i] = (diff > 0 ? diff : 0);
	}
}

lli computeCostForRegion(int r){
	int tol = tolerance[r];
	int bus = busCost[r];
	if (tol >= children) {return bus;}

	lli oneBusCost = (lli) compensation[r];
	oneBusCost *= children;
	oneBusCost += bus;
	
	if (tol <= 0) {
		// evil corner case >:D
		return oneBusCost;
	}
	lli busCount = (children + tol - 1) / tol;
	lli manyBusCost = busCount * bus;

	return (oneBusCost < manyBusCost) ? oneBusCost : manyBusCost;
}

lli computeMinCost(){
	lli total = 0;
	for (int r = 0; r < regions; r++){
		total += computeCostForRegion(r);
	}
	return total;
}


int main(){
	readInput();
	lli totalCost = computeMinCost();
#ifdef ONLINE_JUDGE
	printf("%I64d", totalCost);
#else
	printf("%lld", totalCost);
#endif
}
#include <cstdio>
#include <cstdlib>
using namespace std;
// codeforces submission -- round 0x86 -- betaveros

int passengers, planes;
int seats[1000];

void readInput(){
	scanf("%d %d", &passengers, &planes);
	for (int i = 0; i < planes; i++){
		scanf("%d", &(seats[i]));
	}
}

int comp(const void * a, const void * b){
	return (*(int*)a) - (*(int*)b);
}

void sortPlanes(){
	qsort(seats, planes, sizeof(int), comp);
	// for (int i = 0; i < planes; i++) printf("%d,", seats[i]);
}

int maxEarned(){
	int cost = 0;
	int seatsCopy[1000];
	for (int i = 0; i < planes; i++){
		seatsCopy[i] = seats[i];
	}
	for (int p = 0; p < passengers; p++){
		int maxCost = seatsCopy[planes-1];
		int lastPlane = planes - 1;
		while (lastPlane >= 0 && seatsCopy[lastPlane] == maxCost) lastPlane--;
		lastPlane++;
		seatsCopy[lastPlane]--;
		cost += maxCost;
	}
	return cost;
}

int minEarned(){
	int cost = 0;
	int seatsCopy[1000];
	for (int i = 0; i < planes; i++){
		seatsCopy[i] = seats[i];
	}
	int firstPlane = 0;
	for (int p = 0; p < passengers; p++){
		while (seatsCopy[firstPlane] == 0) firstPlane++;
		cost += seatsCopy[firstPlane];
		seatsCopy[firstPlane]--;
	}
	return cost;
}

int main(){
	readInput();
	sortPlanes();
	printf("%d %d", maxEarned(), minEarned());
}
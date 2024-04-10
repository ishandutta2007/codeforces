#include <cstdio>
using namespace std;
// codeforces submission -- round 0x86 -- betaveros

int peaks[101];
int valleys[101];
int n, k;
void readInput(){
	scanf("%d", &n);
	scanf("%d", &k);
	for (int i = 0; i < n; i++){
		scanf("%d", &(valleys[i]));
		scanf("%d", &(peaks[i]));
	}
	scanf("%d", &(valleys[n]));
}

bool canLower(int p){
	return (peaks[p] > valleys[p] + 1) && (peaks[p] > valleys[p+1] + 1);
}

void computePolyline(){
	int i = 0;
	while (k > 0){
		if (canLower(i)){
			peaks[i]--;
			k--;
		}
		i++;
	}
}

void printPolyline(){
	for (int i = 0; i < n; i++){
		printf("%d ", valleys[i]);
		printf("%d ", peaks[i]);
	}
	printf("%d\n", valleys[n]);
}

int main(){
	readInput();
	computePolyline();
	printPolyline();
}
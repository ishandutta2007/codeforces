#include <cstdio>
using namespace std;
int a[50];
int b[50];
int m;
int n;
void read(){
	scanf("%d", &m);
	for (int i = 0; i < m; i++){
		scanf("%d", &(a[i]));
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &(b[i]));
	}
}
int main(){
	read();
	int bestRatio = 0, occurrences = 0;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (b[j] % a[i] == 0){
				// valid pair
				int ratio = b[j] / a[i];
				if (ratio > bestRatio){
					bestRatio = ratio;
					occurrences = 1;
				} else if (ratio == bestRatio) {
					occurrences++;
				}
			}
		}
	}
	printf("%d\n", occurrences);
}
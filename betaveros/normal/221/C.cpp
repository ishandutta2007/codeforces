#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAXLEN 100001
int a[MAXLEN];
int asorted[MAXLEN];

int cmp(const void * a, const void * b){
	return (*((int*)a)) - (*((int*)b));
}

int main(){
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &(a[i]));
		asorted[i] = a[i];
	}
	// wtf did I just do here
	qsort(asorted, n, sizeof(int), cmp);
	int diffs = 0;
	for (int i = 0; i < n; i++){
		if (a[i] != asorted[i]){
			diffs++;
			if (diffs > 2){
				printf("NO");
				return 0;
			}
		}
	}
	printf("YES");
	return 0;
}
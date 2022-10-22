#include<cstdio>

using namespace std;

int n;
bool a[100], b[100];

int main(){
	scanf("%d", &n);
	int z = 1;
	n *= n;
	while (n--){
		int c, d;	scanf("%d%d", &c, &d);
		if (!a[c] && !b[d]){
			printf("%d ", z);
			a[c] = b[d] = 1;
		}
		z++;
	}
	printf("\n");
	return 0;
}
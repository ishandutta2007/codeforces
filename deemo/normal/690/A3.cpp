#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int te;	scanf("%d", &te);
	while (te--){
		int n, ind;	scanf("%d %d", &n, &ind);	ind--;
		int sm = 0;
		for (int i = 0; i < n - 1; i++){
			int temp;	scanf("%d", &temp);
			sm += temp - 1;
		}
		sm %= n;
	
		int ans = (ind >= sm?ind - sm:n - (sm - ind));
		printf("%d\n", ans + 1);
	}
	return 0;
}
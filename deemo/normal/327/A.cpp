#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
	int n;	scanf("%d", &n);
	int ans = 0, maxi = -1e9, cnt = 0;
	while (n--){
		int temp;	scanf("%d", &temp);
		if (temp == 0)	cnt++;
		else	cnt--;
		maxi = max(maxi, cnt);
		if (cnt < 0)	cnt = 0;
		if (temp == 1)	ans++;
	}
	printf("%d\n", ans + maxi);
	return 0;
}
//Let me photograph you in this light
//In case it is the last time
//That we might be exactly like we were
//Before we realized
//We were sad of getting old..

#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

const int MAX = 1e5 + 3;

int n;
int a[MAX], b[MAX];
pair<int, int>	vec[MAX];

int main(){
	scanf("%d", &n);
	printf("YES\n");
	for (int i = 0; i < n; i++){
		scanf("%d", &vec[i].first);
		vec[i].second = i;
	}
	sort(vec, vec + n);

	int x = n / 3;
	if (n % 3)	x++;
	for (int i = 0; i < n; i++){
		int temp = vec[i].first;
		int j = vec[i].second;

		if (i < x){
			a[j] = temp;
			b[j] = 0;
		}
		else if (i < 2 * x){
			a[j] = 0;
			b[j] = temp;
		}
		else{
			int t = i - 2 * x;
			b[j] = x - 1 - t;
			a[j] = temp - b[j];
		}
	}

	for (int i = 0; i < n; i++)	printf("%d ", a[i]);
	printf("\n");
	for (int i = 0; i < n; i++)	printf("%d ", b[i]);
	printf("\n");
	return 0;
}
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int x;
vector<int>	vec(12);

int main(){
	scanf("%d", &x);
	for (int i = 0; i < 12; i++)
		scanf("%d", &vec[i]);
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	
	int k = 0, cnt = 0;
	while (k < x && cnt < 12){
		k += vec[cnt];
		cnt++;
	}

	if (k < x)	printf("-1\n");
	else printf("%d\n", cnt);

	return 0;
}
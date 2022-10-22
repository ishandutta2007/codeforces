#include<cstdio>
#include<algorithm>

using namespace std;

int a[5];

int main(){
	for (int i = 0 ; i < 4; i++)
		scanf("%d", &a[i]);
	sort(a, a + 4);
	int cnt = 0;
	for (int i = 0 ; i < 3; i++)
		if (a[i] == a[i + 1])	cnt++;
	printf("%d\n", cnt);
	return	0;
}
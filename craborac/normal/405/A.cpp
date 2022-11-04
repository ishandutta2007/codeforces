#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

int mas[100];

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &mas[i]);
	}
	sort(mas,mas + n);
	for(int i = 0; i < n; i++)
		printf("%d ", mas[i]);
	return 0;
}
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int MAXN = 1e6;

int m, vec[MAXN + 10], ans[MAXN + 10], sz;
int match[MAXN + 10];
bool pic[MAXN + 10];

int main(){
	for (int i = 1, j = MAXN; i <= MAXN; i++, j--)
		match[i] = j;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &vec[i]), pic[vec[i]] = 1;

	int cnt = 0;
	for (int i = 0; i < m; i++)
		if (!pic[match[vec[i]]])
			ans[sz++] = match[vec[i]];
		else
			cnt++;
	cnt /= 2;
	for (int i = 1; i <= MAXN && cnt; i++)
		if (!pic[i] && !pic[match[i]])
			cnt--, ans[sz++] = i, ans[sz++] = match[i];
	
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
int main()
{
	int num, kai;
	scanf("%d%d", &num, &kai);
	deque<int>deq;
	for (int i = 0; i < num; i++)deq.push_back(i + 1);
	for (int i = 0; i < kai; i++)
	{
		if (i % 2 == 0)printf("%d ", deq[0]), deq.pop_front();
		else printf("%d ", deq[deq.size() - 1]), deq.pop_back();
	}
	if (kai % 2 == 0)reverse(deq.begin(), deq.end());
	for (int i = 0; i < deq.size(); i++)printf("%d ", deq[i]);
	printf("\n");
}
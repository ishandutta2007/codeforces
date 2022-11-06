#include <stdio.h>
#include <vector>



int main()
{
	std::vector<int> answer; int n, v; scanf("%d", &n); scanf("%d", &v);
	for (int i=1; i<=n; i++)
	{
		bool bit=false; int k; scanf("%d", &k);
		for (int j=0; j<k; j++)
		{
			int s; scanf("%d", &s);
			if (s < v)
				bit=true;
		}
		if (bit)
			answer.push_back(i);
	}
	printf("%d\n", int(answer.size()));
	for (auto it=answer.begin(); it!=answer.end(); it++)
		printf("%d ", *it);
	printf("\n");
	return 0;
}
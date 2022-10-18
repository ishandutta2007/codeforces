#include<stdio.h>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

vector<int> B1, B2;

int main()
{
	int n, i, t, w, j;
	int ans, sz1, sz2, w1, w2;

	scanf("%d", &n);
	for(i = 1; i <= n; i++)
	{
		scanf("%d%d", &t, &w);

		if(t==1) B1.push_back(w);
		else B2.push_back(w);
	}

	B1.push_back(0);
	B2.push_back(0);

	sort(B1.begin(), B1.end());
	sort(B2.begin(), B2.end());

	w1 = 0;
	sz1 = B1.size();
	sz2 = B2.size();

	ans = 200;
	for(i = 0; i < B1.size(); i++)
	{
		w1 += B1[i];

		w2 = 0;
		for(j = 0; j < B2.size(); j++)
		{
			w2 += B2[j];

			if(w1 + w2 <= 1*(sz1 - 1 - i) + 2*(sz2 - 1 - j))
			{
				if( ans > 1*(sz1 - 1 - i) + 2*(sz2 - 1 - j) )
					ans = 1*(sz1 - 1 - i) + 2*(sz2 - 1 - j);
			}
		}
	}

	printf("%d\n", ans);


	return 0;
}
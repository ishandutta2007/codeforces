#include<stdio.h>
#include<vector>
using namespace std;

vector< vector<int> > V;

int d[10];
int i1, i2, i3, i4;
int dig[20], total;
int used[20];

void solve(int at)
{
	if(at > total - at - 1)
	{
		int s1, s2, s3, s4, i;

		for(i = 0; i <= 9; i++)
			if(d[i] && !used[i])
				return;

		s1 = s2 = s3 = s4 = 0;
		if(i1 > 1 && dig[0]==0) return;
		if(i2 > 1 && dig[i1]==0) return;
		if(i3 > 1 && dig[i1+i2]==0) return;
		if(i4 > 1 && dig[i1+i2+i3]==0) return;

		for(i = 0; i < i1; i++) s1 = s1*10 + dig[i];
		for(i = i1; i < i1+i2; i++) s2 = s2*10 + dig[i];
		for(i = i1+i2; i < i1+i2+i3; i++) s3 = s3*10 + dig[i];
		for(i = i1+i2+i3; i < i1+i2+i3+i4; i++) s4 = s4*10 + dig[i];

		if(s1>255 || s2>255 || s3>255 || s4>255) return;
		
		vector<int> S(4, 0);
		S[0] = s1;
		S[1] = s2;
		S[2] = s3;
		S[3] = s4;
		V.push_back(S);
		return;
	}

	int i;

	for(i = 0; i <= 9; i++)
	{
		if( !d[i] )
			continue;

		used[i]++;
		dig[at] = i;
		dig[total - at - 1] = i;

		solve(at + 1);

		dig[at] = dig[total - at - 1] = -1;
		used[i]--;
	}
}

int main()
{
	int n, a, i;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &a);
		d[a] = 1;
	}

	for(i = 0; i <= 19; i++)
		dig[i] = -1;

	for(i1 = 1; i1 <= 3; i1++)
		for(i2 = 1; i2 <= 3; i2++)
			for(i3 = 1; i3 <= 3; i3++)
				for(i4 = 1; i4 <= 3; i4++)
				{
					total = i1 + i2 + i3 + i4;
					solve(0);
				}

	printf("%d\n", V.size());
	for(i = V.size()-1; i >= 0; i--)
		printf("%d.%d.%d.%d\n", V[i][0], V[i][1], V[i][2], V[i][3]);

	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int score[56];
int flag[56][56];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n*(n-1)/2-1;i++)
	{
		int x,y;
		cin>>x>>y;
		score[x]++;
		score[y]--;
		flag[x][y] = 1;
		flag[y][x] = 1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(flag[i][j] == 0 && i!=j)
			{
				if(score[i]>score[j])
				{
					cout<<i<<" "<<j<<endl;
				}
				else
				{
					cout<<j<<" "<<i<<endl;
				}
				exit(0);
			}
		}
	}
	return 0;	
}
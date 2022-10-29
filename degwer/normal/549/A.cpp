#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int map[52][52];
int main()
{
	int mx,my;
	scanf("%d%d",&mx,&my);
	for(int i=0;i<mx;i++)for(int j=0;j<my;j++)scanf(" %c",&map[i][j]);
	int cnt=0;
	vector<char>d;
	d.push_back('a');
	d.push_back('c');
	d.push_back('e');
	d.push_back('f');
	for(int i=0;i<mx-1;i++)
	{
		for(int j=0;j<my-1;j++)
		{
			vector<char>v;
			v.push_back(map[i][j]);
			v.push_back(map[i+1][j]);
			v.push_back(map[i][j+1]);
			v.push_back(map[i+1][j+1]);
			sort(v.begin(),v.end());
			if(d==v)cnt++;
		}
	}
	printf("%d\n",cnt);
}
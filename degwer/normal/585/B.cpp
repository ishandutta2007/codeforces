#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
char map[3][150];
int main()
{
	int data;
	scanf("%d",&data);
	for(int p=0;p<data;p++)
	{
		int mx,tt;
		scanf("%d%d",&mx,&tt);
		for(int i=0;i<3;i++)for(int j=0;j<150;j++)map[i][j]='.';
		for(int i=0;i<3;i++)for(int j=0;j<mx;j++)scanf(" %c",&map[i][j]);
		int beg=-1;
		for(int i=0;i<3;i++)if(map[i][0]=='s')beg=i;
		bool f[3];
		fill(f,f+3,false);
		f[beg]=true;
		for(int i=0;i<120;i+=3)
		{
			bool zf[3];
			fill(zf,zf+3,false);
			if(f[0])
			{
				if(map[0][i+1]=='.'&&map[0][i+1]=='.'&&map[0][i+2]=='.'&&map[0][i+3]=='.')zf[0]=true;
				if(map[0][i+1]=='.'&&map[1][i+1]=='.'&&map[1][i+2]=='.'&&map[1][i+3]=='.')zf[1]=true;
			}
			if(f[1])
			{
				if(map[1][i+1]=='.'&&map[0][i+1]=='.'&&map[0][i+2]=='.'&&map[0][i+3]=='.')zf[0]=true;
				if(map[1][i+1]=='.'&&map[1][i+1]=='.'&&map[1][i+2]=='.'&&map[1][i+3]=='.')zf[1]=true;
				if(map[1][i+1]=='.'&&map[2][i+1]=='.'&&map[2][i+2]=='.'&&map[2][i+3]=='.')zf[2]=true;
			}
			if(f[2])
			{
				if(map[2][i+1]=='.'&&map[1][i+1]=='.'&&map[1][i+2]=='.'&&map[1][i+3]=='.')zf[1]=true;
				if(map[2][i+1]=='.'&&map[2][i+1]=='.'&&map[2][i+2]=='.'&&map[2][i+3]=='.')zf[2]=true;
			}
			for(int j=0;j<3;j++)f[j]=zf[j];
		}
		if(f[0]||f[1]||f[2])printf("YES\n");
		else printf("NO\n");
	}
}
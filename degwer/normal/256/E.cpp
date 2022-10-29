#include<stdio.h>
#include<vector>
#include<algorithm>
#define SIZE 131072
using namespace std;
typedef long long ll;
ll mod=777777777;
class segtree
{
public:
	int mat[4][4];
	ll seg[SIZE*2][4][4];
	inline void init(int num)
	{
		for(int i=0;i<num;i++)
		{
			seg[i+SIZE][0][0]=seg[i+SIZE][1][1]=seg[i+SIZE][2][2]=1;
		}
		for(int i=num;i<SIZE;i++)
		{
			seg[i+SIZE][3][3]=1;
		}
		for(int p=SIZE-1;p>=1;p--)
		{
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<4;k++)
				{
					if(mat[j][k])
					{
						for(int i=0;i<4;i++)
						{
							for(int l=0;l<4;l++)
							{
								seg[p][i][l]+=seg[p*2][i][j]*seg[p*2+1][k][l];
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					seg[p][i][j]%=mod;
				}
			}
		}
	}
	inline void update(int node,int num)
	{
		node+=SIZE;
		for(int i=1;i<=3;i++)
		{
			if(num!=i)
			{
				seg[node][i-1][i-1]=0;
			}
			else
			{
				seg[node][i-1][i-1]=1;
			}
		}
		if(num==0)
		{
			seg[node][0][0]=seg[node][1][1]=seg[node][2][2]=1;
		}
		if(num==4)
		{
			seg[node][3][3]=1;
		}
		for(;;)
		{
			node/=2;
			if(node==0)
			{
				break;
			}
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					seg[node][i][j]=0;
				}
			}
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<4;k++)
				{
					if(mat[j][k])
					{
						for(int i=0;i<4;i++)
						{
							for(int l=0;l<4;l++)
							{
								seg[node][i][l]+=seg[node*2][i][j]*seg[node*2+1][k][l];
							}
						}
					}
				}
			}
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
				{
					seg[node][i][j]%=mod;
				}
			}
		}
	}
};
segtree tree;
int main()
{
	int num,query;
	scanf("%d%d",&num,&query);
	tree.mat[0][3]=tree.mat[1][3]=tree.mat[2][3]=tree.mat[3][3]=1;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&tree.mat[i][j]);
		}
	}
	tree.init(num);
	for(int i=0;i<query;i++)
	{
		for(int j=0;j<4;j++)
		{
			ll s=0;
			for(int k=0;k<4;k++)
			{
				for(int l=0;l<4;l++)
				{
					s+=tree.seg[j+SIZE][k][l];
				}
			}
		}
		int za,zb;
		scanf("%d%d",&za,&zb);
		tree.update(za-1,zb);
		ll sum=0;
		for(int j=0;j<4;j++)
		{
			for(int k=0;k<4;k++)
			{
				sum+=tree.seg[1][j][k];
			}
		}
		sum%=mod;
		printf("%I64d\n",sum);
	}
}
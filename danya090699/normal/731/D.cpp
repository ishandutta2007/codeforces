#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int *a, int *b){return (a[0]<b[0]);}
int main()
{
	//ifstream in("input.txt");
	int n, c, l=0, r=1000000, pos=1;
	scanf("%d%d", &n, &c);
	vector <int> wo[n];
	vector <int*> za;
	for(int a=0; a<n; a++)
	{
		int q;
		scanf("%d", &q);
		for(int b=0; b<q; b++)
		{
			int x;
			scanf("%d", &x);
			wo[a].push_back(x);
		}
		if(a!=0)
		{
			int yk=0, m=min(wo[a-1].size(), wo[a].size());
			while(yk<m)
			{
				int fi=wo[a-1][yk], se=wo[a][yk];
				if(fi!=se)
				{
					int g1, g2;
					if(fi<se)
					{
						g1=c-se+1, g2=c-fi;
						za.push_back(new int[2]);
						za.back()[0]=g1, za.back()[1]=g2;
					}
					else
					{
						g1=c-fi+1, g2=c-se;
						l=max(l, g1), r=min(r, g2);
					}
					break;
				}
				else yk++;
			}
			if(l>r)
			{
				pos=0;
				break;
			}
			if((yk==m)and(wo[a-1].size()>wo[a].size()))
			{
				pos=0;
				break;
			}
		}
	}
	if(pos)
	{
		sort(za.begin(), za.end(), comp);
		za.push_back(new int[2]);
		za.back()[0]=1000000, za.back()[1]=1000000;
		int pr=-1, ans=-1;
		for(int a=0; a<za.size(); a++)
		{
			if(pr+1<za[a][0])
			{
				int g1=max(l, pr+1), g2=min(r, za[a][0]-1);
				if(g1<=g2)
				{
					ans=g1;
					break;
				}
			}
			pr=max(pr, za[a][1]);
		}
		cout<<ans;
	}
	else cout<<-1;
}
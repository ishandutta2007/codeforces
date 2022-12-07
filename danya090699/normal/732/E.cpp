#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool comp(int *a, int *b){return (a[0]<b[0]);}
int main()
{
	ifstream in("input.txt");
	int n, m, sum=0, q=0;
	scanf("%d%d", &n, &m);
	int *co[n], *ro[m], us[m], an[m], an2[n];
	for(int a=0; a<n; a++)
	{
		co[a]=new int[2];
		scanf("%d", &co[a][0]);
		co[a][1]=a;
		an2[a]=0;
	}
	for(int a=0; a<m; a++)
	{
		ro[a]=new int[2];
		scanf("%d", &ro[a][0]);
		ro[a][1]=a;
		us[a]=0, an[a]=0;
	}
	sort(co, co+n, comp);
	sort(ro, ro+m, comp);
	int le=0;
	while(1==1)
	{
		int yk=0;
		for(int a=0; a<n; a++)
		{
			if(an2[co[a][1]]==0)
			{
				int cmo=co[a][0];
				while(yk<m)
				{
					if(cmo>ro[yk][0]) yk++;
					else if(cmo<ro[yk][0]) break;
					else
					{
						if(us[ro[yk][1]]) yk++;
						else
						{
							an[ro[yk][1]]=le;
							an2[co[a][1]]=ro[yk][1]+1;
							us[ro[yk][1]]=1;
							sum+=le, q++;
							break;
						}
					}
				}
			}
		}
		for(int a=0; a<m; a++)
		{
			if(ro[a][0]==1) ro[a][0]=0;
			else ro[a][0]=ceil((ro[a][0]*1.0)/2);
		}
		le++;
		if(ro[m-1][0]==0) break;
	}
	printf("%d %d\n", q, sum);
	for(int a=0; a<m; a++) printf("%d ", an[a]);
	printf("\n");
	for(int a=0; a<n; a++) printf("%d ", an2[a]);
}
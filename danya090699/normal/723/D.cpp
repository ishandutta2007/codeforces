#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, k, pos, q, **map, **us, ans=0;
vector <int*> oz;
void rec(int y, int x)
{
	us[y][x]=1, q++;
	if((y==0)or(y==n-1)or(x==0)or(x==m-1)) pos=0;
	if(y+1<n) if((map[y+1][x]==0)and(us[y+1][x]==0)) rec(y+1, x);
	if(y-1>=0) if((map[y-1][x]==0)and(us[y-1][x]==0)) rec(y-1, x);
	if(x+1<m) if((map[y][x+1]==0)and(us[y][x+1]==0)) rec(y, x+1);
	if(x-1>=0) if((map[y][x-1]==0)and(us[y][x-1]==0)) rec(y, x-1);
}
void rec2(int y, int x)
{
	map[y][x]=1;
	if(map[y+1][x]==0) rec2(y+1, x);
	if(map[y-1][x]==0) rec2(y-1, x);
	if(map[y][x+1]==0) rec2(y, x+1);
	if(map[y][x-1]==0) rec2(y, x-1);
}
bool comp(int *a, int *b){return (a[2]<b[2]);}
int main()
{
	ifstream in("input.txt");
	cin>>n>>m>>k;
	map=new int*[n], us=new int*[n];
	for(int a=0; a<n; a++)
	{
		map[a]=new int[m], us[a]=new int[m];
		for(int b=0; b<m; b++)
		{
			char ch;
			cin>>ch;
			if(ch=='*') map[a][b]=1;
			else map[a][b]=0;
			us[a][b]=0;
		}
	}
	for(int a=0; a<n; a++)
	{
		for(int b=0; b<m; b++)
		{
			if((map[a][b]==0)and(us[a][b]==0))
			{
				pos=1, q=0;
				rec(a, b);
				if(pos)
				{
					oz.push_back(new int[3]);
					oz.back()[0]=a, oz.back()[1]=b, oz.back()[2]=q;
				}
			}
		}
	}
	//cout<<oz.size();
	sort(oz.begin(), oz.end(), comp);
	//cout<<oz[0][2];
	while(k<oz.size())
	{
		//cout<<ans;
		ans+=oz[0][2];
		rec2(oz[0][0], oz[0][1]);
		oz.erase(oz.begin());
	}
	cout<<ans<<"\n";
	for(int a=0; a<n; a++)
	{
		for(int b=0; b<m; b++)
		{
			if(map[a][b]) cout<<"*";
			else cout<<".";
		}
		cout<<"\n";
	}
}
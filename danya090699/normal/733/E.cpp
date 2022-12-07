#include <iostream>
#include <fstream>
#include <vector>
#define int long long
using namespace std;
main()
{
	ifstream in("input.txt");
	int n;
	cin>>n;
	char ar[n];
	for(int a=0; a<n; a++) cin>>ar[a];
	vector <int> dow(1), up(1);
	dow[0]=0, up[0]=0;
	for(int a=0; a<n; a++)
	{
		if(ar[a]=='D')
		{
			dow.push_back(a), dow.back()+=dow[dow.size()-2];
		}
	}
	for(int a=n-1; a>=0; a--)
	{
		if(ar[a]=='U')
		{
			up.push_back(n-1-a), up.back()+=up[up.size()-2];
		}
	}
	int ykd=0, yku=up.size()-1;
	for(int a=0; a<n; a++)
	{
		int god, gou, an, add;
		if(ar[a]=='D')
		{
			ykd++;
			god=dow.size()-1-ykd, gou=up.size()-1-yku;
			if(gou<=god)
			{
				god=gou, add=a+1;
			}
			else
			{
				gou=god+1, add=n-a;
			}
		}
		else
		{
			god=dow.size()-1-ykd, gou=up.size()-1-yku;
			if(god<=gou)
			{
				gou=god, add=n-a;
			}
			else
			{
				god=gou+1, add=a+1;
			}
		}
		an=dow[ykd+god]-dow[ykd]-a*god+up[yku+gou]-up[yku]-(n-1-a)*gou;
		an=an*2+add;
		cout<<an<<" ";
		if(ar[a]=='U') yku--;
	}
}
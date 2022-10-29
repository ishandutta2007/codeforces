#include<stdio.h>
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int wl(char a,char b)
{
	if((a=='R'&&b=='S')||(a=='S'&&b=='P')||(a=='P'&&b=='R'))
	{
		return 1;
	}
	if(a==b)
	{
		return 0;
	}
	return -1;
}
int main()
{
	int kai;
	scanf("%d",&kai);
	string sta,stb;
	cin>>sta;
	cin>>stb;
	vector<int>vec;
	int wa=0,wb=0;
	for(int i=0;i<sta.size()*stb.size();i++)
	{
		int ia=i%sta.size();
		int ib=i%stb.size();
		int kek=wl(sta[ia],stb[ib]);
		vec.push_back(kek);
		if(kek==1)
		{
			wa++;
		}
		if(kek==-1)
		{
			wb++;
		}
		
	}
	int rea,reb;
	rea=(kai/(sta.size()*stb.size()))*wa;
	reb=(kai/(sta.size()*stb.size()))*wb;
	for(int k=0;k<kai%(sta.size()*stb.size());k++)
	{
		if(vec[k]==1)
		{
			rea++;
		}
		if(vec[k]==-1)
		{
			reb++;
		}
	}
	printf("%d %d\n",reb,rea);
}
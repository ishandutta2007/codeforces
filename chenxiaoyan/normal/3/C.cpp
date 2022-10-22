#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	bool mara=false,marb=false;
	const int lin[][3][2]={{{0,0},{0,1},{0,2}},{{1,0},{1,1},{1,2}},{{2,0},{2,1
	},{2,2}},{{0,0},{1,0},{2,0}},{{0,1},{1,1},{2,1}},{{0,2},{1,2},{2,2}},{{0,0
	},{1,1},{2,2}},{{2,0},{1,1},{0,2}}};
	int i,a=0,b=0;
	string boa[3];
	for(i=0;i<3;i++)
		cin>>boa[i];
	for(i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			a+=boa[i][j]=='X';
			b+=boa[i][j]=='0';
		}
	if(a!=b&&a!=b+1)
	{
		cout<<"illegal";
		return 0;
	}
	for(i=0;i<8;i++)
	{
		if(boa[lin[i][0][0]][lin[i][0][1]]=='X'&&boa[lin[i][1][0]][lin[i][1][1
		]]=='X'&&boa[lin[i][2][0]][lin[i][2][1]]=='X')
			mara=true;
		if(boa[lin[i][0][0]][lin[i][0][1]]=='0'&&boa[lin[i][1][0]][lin[i][1][1
		]]=='0'&&boa[lin[i][2][0]][lin[i][2][1]]=='0')
			marb=true;
	}
	if(mara&&marb||mara&&a!=b+1||marb&&a!=b)
	{
		cout<<"illegal";
		return 0;
	}
	if(mara)
	{
		cout<<"the first player won";
		return 0;
	}
	if(marb)
	{
		cout<<"the second player won";
		return 0;
	}
	if(a+b==9)
	{
		cout<<"draw";
		return 0;
	}
	cout<<(a==b?"first":"second");
	return 0;
}
/*1
X0X
.0.
.X.
*/
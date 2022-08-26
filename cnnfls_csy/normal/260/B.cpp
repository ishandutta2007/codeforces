#include <iostream>
#include <algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iomanip>
#include<map>
#define sqr(x) (x)*(x)
using namespace std;
string st;
int n,m,i,j,k,mx,cnt[45][45][5];
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool check(string st)
{
	if (st[0]=='-'||st[1]=='-'||st[2]!='-'||st[3]=='-'||st[4]=='-'||st[5]!='-'||st[6]=='-'||st[7]=='-'||st[8]=='-'||st[9]=='-') return 0;
	if (st.substr(6,4)<"2013"||st.substr(6,4)>"2015") return 0;
	if (st.substr(3,2)<"01"||st.substr(3,2)>"12") return 0;
	int x,y;
	sscanf(st.substr(3,2).c_str(),"%d",&x);
	sscanf(st.substr(0,2).c_str(),"%d",&y);
	if (y<1||y>days[x]) return 0;
	return 1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>st;
	for (i=0;i+9<st.length();i++)
	{
		string st1=st.substr(i,10);
		if (check(st1))
		{
			int x,y,z;
			sscanf(st1.substr(0,2).c_str(),"%d",&x);
			sscanf(st1.substr(3,2).c_str(),"%d",&y);
			sscanf(st1.substr(9,1).c_str(),"%d",&z);
			cnt[x][y][z]++;
		}
	}
	mx=-1;
	int sx,sy,sz;
	for (i=3;i<=5;i++)
	{
		for (j=1;j<=12;j++)
		{
			for (k=1;k<=days[j];k++)
			{
				if (cnt[k][j][i]>mx)
				{
					mx=cnt[k][j][i];
					sx=k;sy=j;sz=i;
				}
			}
		}
	}
	printf("%02d-%02d-201%d",sx,sy,sz);
	return 0;
}
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
char zi[9];
int no,nx,wo,wx;
bool isline(int i,char c)
{
	if(zi[2]==c&&zi[4]==c&&zi[6]==c)
	return true;
	if(zi[0]==c&&zi[4]==c&&zi[8]==c)
	return true;
	if(zi[i]==c&&zi[i+3]==c&&zi[i+6]==c)
	return true;
	if(zi[3*i]==c&&zi[3*i+1]==c&&zi[3*i+2]==c)
	return true;
	return false;
}
int main()
{
	for(int i=0;i<9;i++)
	{
		cin>>zi[i];
		if(zi[i]=='0')
		no++;
		if(zi[i]=='X')
		nx++;
	}
	for(int i=0;i<3;i++)
	{
		wo|=isline(i,'0');
		wx|=isline(i,'X');
	}
	if((wx&&nx!=no+1)||(wo&&nx!=no)||(nx!=no&&nx!=no+1))
	cout<<"illegal";
	else if(wx)
	cout<<"the first player won";
	else if(wo)
	cout<<"the second player won";
	else if(nx+no==9)
	cout<<"draw";
	else if(nx==no)
	cout<<"first";
	else
	cout<<"second";
	return 0;
}
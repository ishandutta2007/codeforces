#include<bits/stdc++.h>
using namespace std;
int x[4],y[4];
inline bool bt(int r1,int l1,int r2,int l2)
{
	if(r1!=r2&&l1!=l2)return false;
	if(r1==r2)
		if(x[2]==r1)
			if((l1<=y[2]&&y[2]<=l2)||(l2<=y[2]&&y[2]<=l1))return false;
	if(l1==l2)
		if(y[2]==l1)
			if((r1<=x[2]&&x[2]<=r2)||(r2<=x[2]&&x[2]<=r1))return false;
	return true;
}
inline bool beat(int r,int l)
{
	if((x[0]!=r||y[0]!=l)&&bt(x[0],y[0],r,l))return true;
	if((x[1]!=r||y[1]!=l)&&bt(x[1],y[1],r,l))return true;
	return abs(r-x[2])<=1&&abs(l-y[2])<=1;
}
int main()
{
	string s;
	for(int i=0;i<4;i++)
		cin>>s,
		x[i]=s[0]-'a',
		y[i]=s[1]-'1';
	for(int i=-1;i<2;i++)
		for(int j=-1;j<2;j++)
		{
			int r=x[3]+i,l=y[3]+j;
			if(r<0||r>7||l<0||l>7)continue;
			if(!beat(r,l))
			{
				cout<<"OTHER";
				return 0;
			}
		}
	cout<<"CHECKMATE";
}
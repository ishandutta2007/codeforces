#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in("input.txt");
	int n, ma=400;
	cin>>n;
	bool fi[ma][ma], fi2[ma][ma][n+1][8];
	for(int a=0; a<ma; a++)
	{
		for(int b=0; b<ma; b++)
		{
			fi[a][b]=0;
			for(int c=0; c<=n; c++) for(int d=0; d<8; d++) fi2[a][b][c][d]=0;
		}
	}
	fi2[ma/2][ma/2][0][0]=1;
	for(int a=0; a<n; a++)
	{
		int x;
		cin>>x;
		for(int b=0; b<ma; b++)
		{
			for(int c=0; c<ma; c++)
			{
				for(int d=0; d<8; d++)
				{
					if(fi2[c][b][a][d]==1)
					{
						int addb=0, addc=0;
						if(d==0 or d==1 or d==7) addc=1;
						if(d==5 or d==4 or d==3) addc=-1;
						if(d==1 or d==2 or d==3) addb=1;
						if(d==7 or d==5 or d==6) addb=-1;
						int cb=b, cc=c;
						for(int i=0; i<x; i++)
						{
							cc+=addc, cb+=addb;
							fi[cc][cb]=1;
						}
						int ne1=d-1, ne2=d+1;
						if(ne1==-1) ne1=7;
						if(ne2==8) ne2=0;
						fi2[cc][cb][a+1][ne1]=1;
						fi2[cc][cb][a+1][ne2]=1;
					}
				}
			}
		}
	}
	int an=0;
	for(int a=0; a<ma; a++) for(int b=0; b<ma; b++) an+=fi[a][b];
	cout<<an;
	//system("PAUSE");
}
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char ar[4][4];
	bool fou=0;
	for(int a=0; a<4; a++) for(int b=0; b<4; b++) cin>>ar[a][b];
	for(int a=0; a<4; a++)
	{
		for(int b=0; b<4; b++)
		{
			if(ar[a][b]=='.')
			{
				int na[8];
				for(int c=0; c<8; c++)
				{
					na[c]=0;
					int addy=0, addx=0, y=a, x=b;
					if(c==7 or c==0 or c==1) addy=-1;
					if(c==5 or c==4 or c==3) addy=1;
					if(c==7 or c==6 or c==5) addx=-1;
					if(c==1 or c==2 or c==3) addx=1;
					while(1==1)
					{
						y+=addy, x+=addx;
						if(y>=0 and y<4 and x>=0 and x<4)
						{
							if(ar[y][x]=='x') na[c]++;
							else break;
						}
						else break;
					}
				}
				if(na[0]+na[4]>1) fou=1;
				if(na[2]+na[6]>1) fou=1;
				if(na[1]+na[5]>1) fou=1;
				if(na[7]+na[3]>1) fou=1;
			}
		}
	}
	if(fou) cout<<"YES";
	else cout<<"NO";
}
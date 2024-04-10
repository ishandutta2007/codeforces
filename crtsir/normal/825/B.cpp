#include<bits/stdc++.h>
using namespace std;
char c[10][10];
bool check(){
	for(int i=0;i<10;i++)
		for(int j=0;j<6;j++)
			if(c[i][j]=='X'&&c[i][j+1]=='X'&&c[i][j+2]=='X'&&c[i][j+3]=='X'&&c[i][j+4]=='X')
				return 1;
	for(int i=0;i<6;i++)
		for(int j=0;j<10;j++)
			if(c[i][j]=='X'&&c[i+1][j]=='X'&&c[i+2][j]=='X'&&c[i+3][j]=='X'&&c[i+4][j]=='X')
				return 1;
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)
			if(c[i][j]=='X'&&c[i+1][j+1]=='X'&&c[i+2][j+2]=='X'&&c[i+3][j+3]=='X'&&c[i+4][j+4]=='X')
				return 1;
	for(int i=4;i<10;i++)
		for(int j=0;j<6;j++)
			if(c[i][j]=='X'&&c[i-1][j+1]=='X'&&c[i-2][j+2]=='X'&&c[i-3][j+3]=='X'&&c[i-4][j+4]=='X')
				return 1;
	return 0;
} 
int main(){
	for(int i=0;i<10;i++)for(int j=0;j<10;j++)cin>>c[i][j];
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
			if(c[i][j]=='.')
			{
				c[i][j]='X';
				if(check()){cout<<"YES";return 0;}
				c[i][j]='.';
			}
	cout<<"NO";
}
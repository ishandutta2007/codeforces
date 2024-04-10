#include<iostream>
#include<cstring>
using namespace std;
int n,can;
string gra[2];
bool mar[2][100001];
void dfs(int wil,bool pos,int h)
{
	if(h>n)
	{
		cout<<"YES";
		exit(0);
	}
	if(h<=wil)
		return;
	if(mar[pos][h])
		return;
	mar[pos][h]=true;
	if(gra[pos][h]=='X')
		return;
	if(!mar[!pos][h+can])
		dfs(wil+1,!pos,h+can);
	if(!mar[pos][h-1])
		dfs(wil+1,pos,h-1);
	if(!mar[pos][h+1])
		dfs(wil+1,pos,h+1);
}
int main()
{
	cin>>n>>can>>gra[0]>>gra[1];
	string spa=" ";
	gra[0]=spa+gra[0];
	gra[1]=spa+gra[1];
	dfs(0,false,1);
	cout<<"NO";
	return 0;
}
/*1
7 3
---X--X
-X--XX-
*/
/*2
6 2
--X-X-
X--XX-
*/
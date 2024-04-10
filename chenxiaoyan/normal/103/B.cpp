#include<iostream>
using namespace std;
int fat[101];
int anc(int x)
{
	if(fat[x]==x)
		return x;
	return fat[x]=anc(fat[x]);
}
void mer(int x,int y)
{
	fat[anc(x)]=anc(y);
}
int main()
{
	int nod,edg,i;
	cin>>nod>>edg;
	for(i=1;i<=nod;i++)
		fat[i]=i;
	for(i=1;i<=edg;i++)
	{
		int x,y;
		cin>>x>>y;
		mer(x,y);
	}
	bool mar=true;
	for(i=1;i<=nod;i++)
		if(anc(i)!=anc(1))
		{
			mar=false;
			break;
		}
	if(mar)
		if(edg==nod)
			cout<<"FHTAGN!";
		else
			cout<<"NO";
	else
		cout<<"NO";
	return 0;
}
/*1
6 6
6 3
6 4
5 1
2 5
1 4
5 4
*/
/*2
6 5
5 6
4 6
3 1
5 1
1 2
*/
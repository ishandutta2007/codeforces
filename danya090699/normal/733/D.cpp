#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
bool comp(int *a, int *b)
{
	if(a[0]!=b[0]) return a[0]<b[0];
	else
	{
		if(a[1]!=b[1]) return a[1]<b[1];
		else return a[2]<b[2];
	}
}
bool comp2(int a, int b) {return a>b;}
int main()
{
	ifstream in("input.txt");
	int n, be=0, an[2];
	cin>>n;
	int *ar[n];
	for(int a=0; a<n; a++)
	{
		ar[a]=new int[4];
		for(int b=0; b<3; b++) cin>>ar[a][b];
		ar[a][3]=a+1;
		sort(ar[a], ar[a]+3, comp2);
	}
	sort(ar, ar+n, comp);
	int yk=0;
	while(yk<n)
	{
		int cux=ar[yk][0], cuy=ar[yk][1];
		while(yk<n)
		{
			if(ar[yk][0]==cux and ar[yk][1]==cuy)
			{
				if(ar[yk][2]>be)
				{
					be=ar[yk][2], an[0]=ar[yk][3], an[1]=0;
				}
				yk++;
			}
			else break;
		}
		if(yk-2>=0)
		{
			if(ar[yk-2][0]==cux and ar[yk-2][1]==cuy)
			{
				if(be<min(cuy, ar[yk-2][2]+ar[yk-1][2]))
				{
					be=min(cuy, ar[yk-2][2]+ar[yk-1][2]), an[0]=ar[yk-2][3], an[1]=ar[yk-1][3];
				}
			}
		}
	}
	if(an[1]==0) cout<<1<<"\n"<<an[0];
	else cout<<2<<"\n"<<an[0]<<" "<<an[1];
}
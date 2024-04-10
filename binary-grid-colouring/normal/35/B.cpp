#include<bits/stdc++.h>
using namespace std;
int n,m,k;
string shelves[34][34]; 
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n>>m>>k;
	while(k--)
	{
		int type,x,y;
		string name;
		cin>>type;
		if(type > 0)
		{
			cin>>x>>y>>name;
			x--;y--;
			bool found = false;
			for(int i=x;i<n && found==false;i++)
			{
				for(int j= (i==x?y:0);j<m && found==false;j++)
				{
					if(shelves[i][j]=="")
					{
						found = true;
						shelves[i][j] = name;	
					}	
				} 
			}
		}
		else
		{
			cin>>name;
			bool found = false;
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					if(shelves[i][j]==name)
					{
						found = true;
						shelves[i][j]="";
						printf("%d %d\n",i+1,j+1);
					}
				}
			}
			if(found==false)
			{
				cout<<-1<<" "<<-1<<endl;
			}
		}
	}
	return 0;
 }
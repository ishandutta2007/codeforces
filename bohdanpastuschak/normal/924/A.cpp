#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define all(x) x.begin(),x.end()


int n,m;
char a[100][100];
int used[100];

int main()
{
	//freopen("In.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
	
	for(int i=0;i<n;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			string cur="";
			for(int j=0;j<m;j++)
				cur+=a[i][j];
			
			for(int i1=i+1;i1<n;i1++)
			{
				string c="";
				for(int j=0;j<m;j++)
					c+=a[i1][j];
				
				if(c==cur)
				{
					used[i1]=1;
					break;
				}
				
				for(int j=0;j<m;j++)
				{
					if(c[j]=='#' && cur[j]=='#')
					{
						cout<<"No";
						return 0;
					}
				}
	
			}
		}
	}
	memset(used,0,sizeof(used));
	for(int i=0;i<m;i++)
	{
		if(!used[i])
		{
			used[i]=1;
			string cur="";
			for(int j=0;j<n;j++)
				cur+=a[j][i];
			
			for(int i1=i+1;i1<m;i1++)
			{
				string c="";
				for(int j=0;j<n;j++)
					c+=a[j][i1];
				
				if(c==cur)
				{
					used[i1]=1;
					break;
				}
				
				for(int j=0;j<n;j++)
				{
					if(c[j]=='#' && cur[j]=='#')
					{
						cout<<"No";
						return 0;
					}
				}
	
			}
		}
	}
	cout<<"Yes";
	
	return 0;
}
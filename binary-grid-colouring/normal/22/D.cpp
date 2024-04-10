#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node
{
	int x,y;
}A[1234];
bool cmp(node a,node b)
{
	return a.y<b.y;
}
int vis[1234];
int ans[1234];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i].x>>A[i].y;
		if(A[i].x>A[i].y)
		{
			swap(A[i].x,A[i].y);
		}
	}
	sort(A+1,A+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			ans[++ans[0]] = A[i].y;
			for(int j=i;j<=n;j++)
			{
				if(A[j].x <= A[i].y && A[i].y <= A[j].y)
				{
					vis[j] = 1;
				}
			}
		}
	}
	cout<<ans[0]<<endl;
	for(int i=1;i<=ans[0];i++){
		cout<<ans[i]<<endl; 
	} 
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,r[53][53],c[53][53];
char x;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>x;
			r[i][j]=(x=='W');
			c[i][j]=r[i][j];
		}
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
			r[i][j]+=r[i][j-1];
	for(int i=1;i<=m;i++)
		for(int j=2;j<=n;j++)
			c[j][i]+=c[j-1][i];
	for(int x1=1;x1<=n;x1++)
		for(int y1=1;y1<=m;y1++)
			if(r[x1][y1]-r[x1][y1-1]==0)
				for(int x2=1;x2<=n;x2++)
					for(int y2=1;y2<=m;y2++)
						if(r[x2][y2]-r[x2][y2-1]==0)
							if(x1!=x2||y1!=y2)
							{
								if(r[x1][max(y1,y2)]-r[x1][min(y1,y2)-1]==0&&c[max(x1,x2)][y2]-c[min(x1,x2)-1][y2]==0)
									continue;
								if(c[max(x1,x2)][y1]-c[min(x1,x2)-1][y1]==0&&r[x2][max(y1,y2)]-r[x2][min(y1,y2)-1]==0)
									continue;
								cout<<"NO";
								return 0;
							}
	cout<<"YES";
}
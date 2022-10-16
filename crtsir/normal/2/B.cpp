#include<bits/stdc++.h>
using namespace std;
int n,num2[1003][1003],num5[1003][1003],xx,yy;
pair<int,char>dp2[1003][1003],dp5[1003][1003];
bool has0=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int a;
			scanf("%d",&a);
			if(a==0){xx=i,yy=j;has0=1;continue;}
			while(a%5==0)a/=5,num5[i][j]++;
			while(a%2==0)a/=2,num2[i][j]++;
		}
	dp2[1][1].first=num2[1][1];dp5[1][1].first=num5[1][1];
	for(int i=2;i<=n;i++)dp2[i][1].first=dp2[i-1][1].first+num2[i][1],dp2[1][i].first=dp2[1][i-1].first+num2[1][i],
						 dp2[i][1].second='D',dp2[1][i].second='R',
						 dp5[i][1].first=dp5[i-1][1].first+num5[i][1],dp5[1][i].first=dp5[1][i-1].first+num5[1][i],
						 dp5[i][1].second='D',dp5[1][i].second='R';
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(dp2[i-1][j].first<dp2[i][j-1].first)
				dp2[i][j].first=dp2[i-1][j].first+num2[i][j],
				dp2[i][j].second='D';
			else
				dp2[i][j].first=dp2[i][j-1].first+num2[i][j],
				dp2[i][j].second='R';
	for(int i=2;i<=n;i++)
		for(int j=2;j<=n;j++)
			if(dp5[i-1][j].first<dp5[i][j-1].first)
				dp5[i][j].first=dp5[i-1][j].first+num5[i][j],
				dp5[i][j].second='D';
			else
				dp5[i][j].first=dp5[i][j-1].first+num5[i][j],
				dp5[i][j].second='R';
	bool res=0;
	if(dp2[n][n]>dp5[n][n])res=1;
	if(dp2[n][n].first&&dp5[n][n].first&&has0){
		cout<<1<<endl;
		for(int i=1;i<xx;i++)cout<<'D';
		for(int i=1;i<yy;i++)cout<<'R';
		for(int i=xx+1;i<=n;i++)cout<<'D';
		for(int i=yy+1;i<=n;i++)cout<<'R';
		return 0;
	}
	string s;
	if(res==0){
		cout<<dp2[n][n].first<<endl;
		int x=n,y=n;
		while(x!=1||y!=1)
		{
			s=dp2[x][y].second+s;
			if(dp2[x][y].second=='D')x--;
			else y--;
		}
	}else{
		cout<<dp5[n][n].first<<endl;
		int x=n,y=n;
		while(x!=1||y!=1)
		{
			s=dp5[x][y].second+s;
			if(dp5[x][y].second=='D')x--;
			else y--;
		}
	}
	cout<<s;
}
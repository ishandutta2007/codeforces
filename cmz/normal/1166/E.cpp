#include<bits/stdc++.h>
using namespace std;
 int kkk;
int m,n;
int a[55][10005]={0};
bool f=0;
 
int main()
{
	int aa=0;
	ios::sync_with_stdio(0);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int num,x;
		cin>>num;
		for(int j=1;j<=num;j++){
			cin>>x;
			a[i][x]=1;
		}
		for(int j=1;j<=n;j++)  a[i][j]==1?a[i][j]=1:a[i][j]=2;
		
		for(int j=1;j<i;j++){
			bool temp=0;
			for(int k=1;k<=n;k++)
				if(a[i][k]==1 && a[j][k]!=2){
					temp=1;
					break;
				}
			if(temp==0){
				f=1;
				break;
			}
		}
		
		if(f==1){
			cout<<"impossible";
			return 0;
		}	
	}
	
	cout<<"possible";
	return 0;
}
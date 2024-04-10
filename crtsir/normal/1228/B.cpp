#include<bits/stdc++.h>
using namespace std;
int n,m,a[1003],b[1003],ans=1;
int c[1003][1003];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){cin>>a[i];for(int j=0;j<a[i];j++)c[i][j]=2;c[i][a[i]]=1;}
	for(int i=0;i<m;i++){cin>>b[i];for(int j=0;j<b[i];j++)c[j][i]+=2;c[b[i]][i]+=1;}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			if(c[i][j]==0)
				ans=ans*2%1000000007;
			else
				if(c[i][j]==3){
					cout<<0;
					return 0;
				}
	}
	cout<<ans; 
}
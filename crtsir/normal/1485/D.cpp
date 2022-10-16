#include<bits/stdc++.h>
using namespace std;
int n,m,a[503][503];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			a[i][j]*=a[i][j];
			a[i][j]*=a[i][j];
		}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			if((i+j)%2)
				cout<<720720+a[i][j]<<' ';
			else
				cout<<720720<<' ';
		cout<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){for(int j=0;j<n;j++)cin>>a[i][j];}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]==1)continue;
			bool OK=false;
			for(int k=0;k<n;k++){
				for(int l=0;l<n;l++){
					if(a[i][k]+a[l][j]==a[i][j])OK=true;
				}
			}
			if(OK==false){cout<<"No"<<endl;return 0;}
		}
	}
	cout<<"Yes"<<endl;
	return 0;
}
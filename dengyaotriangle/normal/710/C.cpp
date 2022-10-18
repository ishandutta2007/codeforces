#include<bits/stdc++.h>

using namespace std;

const int maxn=55;

int n;
int x[maxn][maxn];

int main(){
	cin>>n;
	int cx=0,cy=n/2;
	for(int i=0;i<n*n;i++){
		//cout<<cx<<cy<<endl;
		//cout<<i+1<<','<<cx<<cy<<endl;
		x[cx][cy]=i+1;
		cx--;
		cy++;
		if(cx<0) cx=n-1;
		if(cy==n) cy=0;
		if(x[cx][cy]!=0){
			cx+=2;
			cy--;
		}
		if(cy<0) cy=n-1;
		if(cx>n) cx-=n;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) cout<<x[i][j]<< ' ';
		cout<<endl;
	}
	return 0;
}
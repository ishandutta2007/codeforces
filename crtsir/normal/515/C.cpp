#include<bits/stdc++.h>
using namespace std;
int a[10][4]={{0,0,0,0},{0,0,0,0},{0,0,0,1},{0,0,1,1},{0,0,1,3},{0,1,1,3},{0,1,2,4},{1,1,2,4},{1,1,2,7},{1,1,4,7}},x[4];
int main(){
	string s;
	int n;
	cin>>n>>s;
	for(int i=0;i<n;i++)
		for(int j=0;j<4;j++)
			x[j]+=a[s[i]-'0'][j];
	for(int i=0;i<x[0];i++)cout<<'7',x[1]-=a[6][1],x[2]-=a[6][2],x[3]-=a[6][3];
	for(int i=0;i<x[1];i++)cout<<'5',x[2]-=a[4][2],x[3]-=a[4][3];
	for(int i=0;i<x[2];i++)cout<<'3',x[3]-=a[2][3];
	for(int i=0;i<x[3];i++)cout<<'2';
}
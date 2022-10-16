#include<bits/stdc++.h>
using namespace std;
int T,n,m,r0,c0;
bool vis[103][103];
int main(){
	cin>>n>>m>>r0>>c0;
	cout<<r0<<' '<<c0<<endl;
	cout<<1<<' '<<c0<<endl;
	for(int i=c0+1;i<=m;i++)
		cout<<1<<' '<<i<<endl;
	for(int i=c0-1;i>=1;i--)
		cout<<1<<' '<<i<<endl;
	for(int i=2;i<=n;i++)
		if(i%2==0)
			for(int j=1;j<=m;j++)
				if(i!=r0||j!=c0)
					cout<<i<<' '<<j<<endl;
				else;
		else
			for(int j=m;j>=1;j--)
				if(i!=r0||j!=c0)
					cout<<i<<' '<<j<<endl; 
}
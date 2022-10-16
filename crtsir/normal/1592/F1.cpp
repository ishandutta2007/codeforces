#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s[503];
bool a[503][503],qaq[503][503];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(s[i][j]=='B')
				a[i][j]=1;
			else
				a[i][j]=0;
	int ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			qaq[i][j]=bool(a[i][j]^a[i][j+1]^a[i+1][j]^a[i+1][j+1]);
			ans+=qaq[i][j];
		}bool ok=0;
	if(qaq[n-1][m-1])
		for(int i=0;i<n-1;i++)
			for(int j=0;j<m-1;j++)
				if(qaq[i][j]&&qaq[i][m-1]&&qaq[n-1][j])
					ok=1;
	cout<<ans-ok<<endl;
}
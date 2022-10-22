#include <bits/stdc++.h>
using namespace std;
int n;
int ans=0;
char t[103][103];
int r[103],c[103];
int main(){
	cin>>n;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++){
			cin>>t[i][j];
			if (t[i][j]=='C'){
				r[i]++;
				c[j]++;
			}
		}
	for (int i=0;i<n;i++)
		ans+=r[i]*(r[i]-1)/2;
	for (int i=0;i<n;i++)
		ans+=c[i]*(c[i]-1)/2;
	cout<<ans;
}
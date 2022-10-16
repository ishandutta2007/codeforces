#include<bits/stdc++.h>
using namespace std;
int n,m,cnta[1003],cntb[1003],cnt;
string s;
char c[1003][1003];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s;
		for(int j=0;j<m;j++)
			c[i][j]=s[j],
			cnt=cnt+(s[j]=='*'),
			cnta[i]+=(c[i][j]=='*'),
			cntb[j]+=(c[i][j]=='*');
	}
	for(int i=0;i<n;i++) 
		for(int j=0;j<m;j++) 
			if(cnta[i]+cntb[j]-(c[i][j]=='*')==cnt){
				cout<<"YES\n"<<i+1<<' '<<j+1<<endl;
				return 0;
			}
	cout<<"NO";
}
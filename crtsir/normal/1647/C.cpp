#include<bits/stdc++.h>
using namespace std;
int n,m,t;
string s[103];
int main(){cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>s[i];
		if(s[0][0]=='1'){
			cout<<-1<<endl;
			continue;
		}
		cout<<n*m-1<<endl;
		for(int i=n-1;i>=0;i--)
			for(int j=m-1;j>=0;j--){
				if(i==0&&j==0)continue;
				if(s[i][j]=='0'){
					cout<<i+1<<' '<<j+1<<' '<<1+i<<' '<<j+1<<endl; 
					continue;
				}
				if(i)
					cout<<i<<' '<<j+1<<' '<<i+1<<' '<<j+1<<endl;
				else
					cout<<i+1<<' '<<j<<' '<<i+1<<' '<<j+1<<endl; 
			}
	}
}
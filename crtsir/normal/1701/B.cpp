#include<bits/stdc++.h>
using namespace std;
int T,n;
bool vis[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		memset(vis,0,sizeof(vis));
		cout<<2<<endl;
		for(int i=1;i<=n;i++)
			if(!vis[i]){
				for(int j=i;j<=n;j*=2){
					cout<<j<<' ';
					vis[j]=1;
				}
			}
		cout<<endl;
	}
}
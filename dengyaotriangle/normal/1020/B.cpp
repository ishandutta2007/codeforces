#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int x[maxn];
bool vis[maxn];

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		int cur=i;
		memset(vis,0,sizeof(vis));
		vis[cur]=1;
		while(true){
			cur=x[cur-1];
			//cout<<cur;
			if(vis[cur]){
				cout<<cur<<' ';
				break;
			}
			vis[cur]=1;
		}
	}
	return 0;
}
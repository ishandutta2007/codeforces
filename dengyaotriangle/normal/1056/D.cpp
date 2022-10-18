#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int p[maxn];
int sz[maxn],cnt[maxn];
int n;
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=2;i<=n;i++)cin>>p[i];
	for(int i=n;i>=1;i--){
		if(sz[i]==0)sz[i]=1;
		sz[p[i]]+=sz[i];
		cnt[sz[i]]++;
	}
	int cp=0,cs=0;
	for(int i=1;i<=n;i++){
		while(cs<i){
			cs+=cnt[++cp];
		}
		cout<<cp<<' ';
	} 
	return 0;
}
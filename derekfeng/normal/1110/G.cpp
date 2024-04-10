#include<bits/stdc++.h>
using namespace std;
#define udk {puts("White");return;}
int T,n,d[2000005],u,v,cnt;
vector<int>g[2000005];
char c[2000005];
void sol(){
	scanf("%d",&n);cnt=n;
	for(int i=1;i<=n;i++)g[i].clear(),d[i]=0;
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
		d[u]++,d[v]++;
	}
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)if(c[i]=='W'){
		++cnt;g[cnt].clear();
		g[cnt].push_back(i),g[i].push_back(cnt);
		d[cnt]=3,d[i]++;
	}
	int num=0;
	for(int i=1;i<=cnt;i++){
		if(d[i]>3)udk
		if(d[i]>2){
			num++;
			int tmp=0;
			for(auto x:g[i])tmp+=(d[x]>1);
			if(tmp>1)udk
		}
	}
	if(num==2&&cnt%2==1)udk
	puts("Draw");
}
int main(){
	scanf("%d",&T);
	while(T--)sol();
}
#include<bits/stdc++.h>
using namespace std;
int ans[125004];
char c[125004],t[125004];
char nc[125004],nt[125004];
int a[6],tot,cur=6,n1,n2;
int nxt[125004];
void divset(int x){
	if(x==6){
		int rem=6-tot;
		nt[1]=a[t[1]];
		for(int i=2;i<=n2;i++){
			nt[i]=a[t[i]];
			int now=nxt[i-1];
			while(now&&nt[i]!=nt[now+1])now=nxt[now];
			if(nt[i]==nt[now+1])now++;
			nxt[i]=now;
		}
		int cur=0;
		for(int i=1;i<=n1;i++){
			nc[i]=a[c[i]];
			while(cur&&nt[cur+1]!=nc[i])cur=nxt[cur];
			if(nc[i]==nt[cur+1])cur++;
			if(cur==n2)ans[i]=min(ans[i],rem);
		}
		return;
	}
	a[x]=++tot;
	divset(x+1);
	--tot;
	for(int i=1;i<=tot;i++)a[x]=i,divset(x+1);
}
int main(){
	scanf("%s%s",c+1,t+1);
	n1=strlen(c+1),n2=strlen(t+1);
	for(int i=1;i<=n1;i++)ans[i]=10;
	for(int i=1;i<=n1;i++)c[i]-='a';
	for(int i=1;i<=n2;i++)t[i]-='a';
	divset(0);
	for(int i=n2;i<=n1;i++)printf("%d ",ans[i]);
}
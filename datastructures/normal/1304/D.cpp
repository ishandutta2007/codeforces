#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int t,n,a[200005],du[200005];
int u[200005],v[200005],nxt[200005],first[200005],book[200005];
int cnt,ans[200005],out[200005];
int totm;
inline void add(int uu,int vv){
	int i=++totm;
	u[i]=uu,v[i]=vv;
	nxt[i]=first[u[i]],first[u[i]]=i;
	return;
}
char s[200005];
priority_queue <int>h;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		scanf("%s",s+1);
		totm=cnt=0;
		for (int i=0;i<=n;i++)book[i]=du[i]=first[i]=nxt[i]=0;
		for (int i=1;i<n;i++){
			if (s[i]=='<')add(i,i+1),du[i+1]++;
			else add(i+1,i),du[i]++;
		} 
		for (int i=1;i<=n;i++)
			if (du[i]==0){
				if (!book[i]){
					book[i]=1;
					h.push(i);
				}
			}
		while(!h.empty()){
			ans[++cnt]=h.top();
			h.pop();
			for (int i=first[ans[cnt]];i;i=nxt[i]){
				du[v[i]]--;
				if (du[v[i]]<=0){
					if (book[v[i]]==1)continue;
					book[v[i]]=1;
					h.push(v[i]);
				}
			}
		}
		for (int i=1;i<=n;i++)out[ans[i]]=i;
		for (int i=1;i<=n;i++)printf("%d ",out[i]);cout<<endl;
		totm=cnt=0;
		for (int i=0;i<=n;i++)book[i]=du[i]=first[i]=nxt[i]=0;
		for (int i=1;i<n;i++){
			if (s[i]=='<')add(i,i+1),du[i+1]++;
			else add(i+1,i),du[i]++;
		} 
		for (int i=1;i<=n;i++)
			if (du[i]<=0){
				if (!book[i]){
					book[i]=1;
					h.push(-i);
				}
			}
		while(!h.empty()){
			ans[++cnt]=-h.top();
			h.pop();
			for (int i=first[ans[cnt]];i;i=nxt[i]){
				du[v[i]]--;
				if (du[v[i]]==0){
					if (book[v[i]]==1)continue;
					book[v[i]]=1;
					h.push(-v[i]);
				}
			}
		}
		for (int i=1;i<=n;i++)out[ans[i]]=i;
		for (int i=1;i<=n;i++)printf("%d ",out[i]);cout<<endl;
	}
	return 0;
}
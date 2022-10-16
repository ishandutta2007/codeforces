#include<bits/stdc++.h>
using namespace std;
mt19937 rng(time(0));
int n,all,cnt;
bool fx[1003],ans[1003],q[1003];
int p[1003];
void init(){
	for(int i=0;i<n;i++)
		if(fx[i])
			cout<<'F';
		else
			cout<<'T';
	cout<<endl;
	cin>>all;
}
int query(){
	if(++cnt==674)while(1);
	int ret=0;
	for(int i=0;i<n;i++){
		fx[i]^=q[i];
		if(fx[i])
			cout<<'F';
		else
			cout<<'T';
		fx[i]^=q[i];
		if(q[i])ret++;
	}
	cout<<endl;
	int tmp;
	cin>>tmp;
	return (all-tmp+ret)/2;
}
bool dfs(int x){
	if(p[x]==-1)return ans[x];
	return 1^dfs(p[x]);
}
int main(){
	memset(p,-1,sizeof(p));
	cin>>n;
	for(int i=0;i<n;i++)
		fx[i]=rng()&1;
	init();
	int lst=-1;
	for(int i=0;i<n;i++)
		if(lst==-1)
			lst=i;
		else{
			memset(q,0,sizeof(q));
			q[lst]=1;q[i]=1;
			int ret=query();
			if(ret==0)
				ans[i]=0,ans[lst]=0,lst=-1;
			if(ret==1)
				p[i]=lst;
			if(ret==2)
				ans[i]=1,ans[lst]=1,lst=-1;
		}
	if(lst!=-1){
		memset(q,0,sizeof(q));
		q[lst]=1;
		ans[lst]=query();
	}
	for(int i=0;i<n;i++)
		if(dfs(i)^fx[i])
			cout<<'T';
		else
			cout<<'F';
	cout<<endl;
	exit(0);
}
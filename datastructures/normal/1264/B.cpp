#include <iostream>
#include <cstdio>
using namespace std;
int n,a[15],x[100005],flag,ans[100005];
inline void dfs(int now){
	if (flag==1)return;
	if (now>n){
		flag=1;
		for (int i=1;i<now;i++)ans[i]=x[i];
		return;
	}
	int last=x[now-1];
	if (last==0){
		for (int i=1;i<=4;i++){
			if (a[i]==0)continue;
			x[now]=i;
			a[i]--;
			dfs(now+1);
			a[i]++;
		}
		return;
	}
	if (a[last-1]==0){
		if (a[last+1]==0)return;
		x[now]=last+1;
		a[last+1]--;
		dfs(now+1);
		a[last+1]++; 
	}
	else{
		x[now]=last-1;
		a[last-1]--;
		dfs(now+1);
		a[last-1]++;
	}
	return;
}
int main(){
//	freopen("1264B.in","r",stdin);
//	freopen("1264B.out","w",stdout);
	cin>>a[1]>>a[2]>>a[3]>>a[4];
	n=a[1]+a[2]+a[3]+a[4];
	dfs(1);
	if (flag==0){
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for (int i=1;i<=n;i++)cout<<ans[i]-1<<' ';
	cout<<endl;
	return 0;
}
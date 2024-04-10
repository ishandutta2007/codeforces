#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,a[20005],b[20005];
int fg[5005],num[5005],qwq[5005];
int work(){
	memset(fg,0,sizeof(fg));
	memset(num,0,sizeof(num));
	memset(qwq,0,sizeof(qwq));
	for (int i=1;i<=m;i++){
		if (a[i]>b[i]){
			if (num[a[i]]==0)qwq[a[i]]=b[i];
			else if (fg[a[i]]==0)qwq[a[i]]=min(qwq[a[i]],b[i]);
			num[a[i]]++;
		}
		else{
			if (num[a[i]]==0||fg[a[i]]==0)qwq[a[i]]=b[i];
			else qwq[a[i]]=min(qwq[a[i]],b[i]);
			num[a[i]]++;
			fg[a[i]]=1;
		}
	}
	int mx=0,val=0;
	for (int i=1;i<=n;i++){
		if (num[i]==0)continue;
		if (fg[i]==0)num[i]++;
		mx=max(mx,num[i]);
	}
	for (int i=1;i<=n;i++)
		if (num[i]==mx)val=max(val,qwq[i]);
	int ans=n*(mx-1)+val-1;
	return ans;
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++)cin>>a[i]>>b[i];
	for (int i=1;i<=n;i++){
		cout<<work()<<' ';
		for (int j=1;j<=m;j++){
			a[j]--,b[j]--;
			if (a[j]==0)a[j]=n;
			if (b[j]==0)b[j]=n;
		}
	}
	cout<<endl;
	return 0;
}
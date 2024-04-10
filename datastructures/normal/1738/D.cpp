#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int t,n;
vector<int> e[200005];
int q[200005],head,tail;
int tot,a[200005],kl,kr;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=0;i<=n+1;i++)e[i].clear();
		int fg0=0,fg1=0;
		kl=0,kr=n+1;
		for (int i=1;i<=n;i++){
			int x;
			scanf("%d",&x);
			if (x==0)fg0=1;
			if (x==n+1)fg1=1;
			e[x].push_back(i);
			if (i<x)kl=max(kl,i),kr=min(kr,x-1);
			else kl=max(kl,x),kr=min(kr,i-1);
		}
		head=tail=1;
		if (fg0==1)q[1]=0;
		else q[1]=n+1;
		tot=0;
		while(head<=tail){
			int now=q[head];
			head++;
			if (now>=1&&now<=n)a[++tot]=now;
			for (int i=0;i<(int)e[now].size();i++)
				if (e[e[now][i]].size()==0)q[++tail]=e[now][i];
			for (int i=0;i<(int)e[now].size();i++)
				if (e[e[now][i]].size()>0)q[++tail]=e[now][i];
		}
		cout<<kl<<endl;
		for (int i=1;i<=n;i++)printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}
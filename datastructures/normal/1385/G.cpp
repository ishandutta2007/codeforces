#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int t,n,a[400005];
vector<int> pos[200005];
int dsu[400005],num[400005],book[400005];
vector<int> c[400005];
int find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=find(dsu[x]);
}
void merge(int x,int y){
	if (find(x)==find(y))return;
	x=find(x),y=find(y);
	dsu[x]=y;
	num[y]+=num[x];
	num[x]=0;
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=n;i++)scanf("%d",&a[i+n]);
		for (int i=1;i<=n;i++)pos[a[i]].push_back(i),pos[a[i+n]].push_back(i+n);
		int check_fg=1;
		for (int i=1;i<=n;i++)
			if (pos[i].size()>2)check_fg=0;
		if (check_fg==0){
			puts("-1");
			for (int i=1;i<=n;i++)pos[i].clear();
			continue;
		}
		for (int i=1;i<=2*n;i++){
			dsu[i]=i;
			if (i<=n)num[i]=0;
			else num[i]=1;
		}
		for (int i=1;i<=n;i++){
			int qwq1,qwq2;
			if (pos[a[i]][0]!=i)qwq1=pos[a[i]][0];
			if (pos[a[i]][1]!=i)qwq1=pos[a[i]][1];
			if (pos[a[i+n]][0]!=i+n)qwq2=pos[a[i+n]][0];
			if (pos[a[i+n]][1]!=i+n)qwq2=pos[a[i+n]][1];
			if (qwq1<=n)merge(i,qwq1+n),merge(i+n,qwq1);
			if (qwq1>n)merge(i,qwq1-n),merge(i+n,qwq1);
			if (qwq2<=n)merge(i,qwq2),merge(i+n,qwq2+n);
			if (qwq2>n)merge(i,qwq2),merge(i+n,qwq2-n);
		}
		int fg=1,ans=0;
		for (int i=1;i<=n;i++)
			if (find(i)==find(i+n))fg=0;
		if (fg==1){
			for (int i=1;i<=2*n;i++)c[find(i)].push_back(i);
			for (int i=1;i<=n;i++){
				int len=c[i].size(),qwq=num[i];
				if (qwq*2>len){
					for (int j=0;j<len;j++)
						if (c[i][j]<=n)book[c[i][j]]=1,ans++;
				}
				else{
					for (int j=0;j<len;j++)
						if (c[i][j]>n)book[c[i][j]-n]=1,ans++;
				}
			}
			cout<<ans<<endl;
			for (int i=1;i<=n;i++)
				if (book[i])printf("%d ",i);
			puts("");
		}
		else puts("-1");
		for (int i=1;i<=2*n;i++)c[i].clear();
		for (int i=1;i<=n;i++)book[i]=0,pos[i].clear();
	}
	return 0;
}
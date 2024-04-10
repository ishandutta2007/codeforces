#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int t,n,m,a[300005],x[300005],y[300005];
int cnt[300005];
vector<int> qwq[300005];
map<int,int> book[300005];
int awabook[300005],d[300005],tot;
int val[300005];
int _a[300005];
int lower(int x){
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (_a[mid]<=x)ans=mid,l=mid+1;
		else r=mid-1;
	}
	if (_a[ans]!=x)return -1;
	return ans;
}
void work1(int x){
	for (int i=(int)qwq[x].size()-1;i>0;i--){
		int j=i-1;
		while(j>=0&&book[qwq[x][i]][qwq[x][j]]==1)j--;
		if (j!=-1)val[2*x]=max(val[2*x],_a[qwq[x][i]]+_a[qwq[x][j]]);
	}
	return;
}
void work2(int x,int y){
	for (int i=(int)qwq[x].size()-1;i>=0;i--){
		int j=(int)qwq[y].size()-1;
		while(j>=0&&book[qwq[x][i]][qwq[y][j]]==1)j--;
		if (j!=-1)val[x+y]=max(val[x+y],_a[qwq[x][i]]+_a[qwq[y][j]]); 
		if (j==(int)qwq[y].size()-1)break;
	}
	return;
}
int main(){
	cin>>t;
	while(t--){
		n=read(),m=read();
		for (int i=1;i<=n;i++)a[i]=read(),_a[i]=a[i];
		for (int i=1;i<=m;i++)x[i]=read(),y[i]=read();
		sort(_a+1,_a+1+n);
		for (int i=1;i<=n;i++)a[i]=lower(a[i]),cnt[a[i]]++;
		for (int i=1;i<=m;i++){
			x[i]=lower(x[i]),y[i]=lower(y[i]);
			if (x[i]!=-1&&y[i]!=-1)book[x[i]][y[i]]=book[y[i]][x[i]]=1;
		}
		for (int i=1;i<=n;i++){
			if (cnt[a[i]]>0){
				qwq[cnt[a[i]]].push_back(a[i]);
				if (awabook[cnt[a[i]]]==0)d[++tot]=cnt[a[i]],awabook[cnt[a[i]]]=1;
				cnt[a[i]]=0;
			}
		}
		for (int i=1;i<=tot;i++)sort(qwq[d[i]].begin(),qwq[d[i]].end());
		for (int i=1;i<=tot;i++)work1(d[i]);
		for (int i=1;i<=tot;i++)
			for (int j=i+1;j<=tot;j++)
				work2(d[i],d[j]);
		long long ans=0;
		for (int i=1;i<=n;i++)ans=max(ans,1ll*val[i]*i);
		cout<<ans<<endl;
		for (int i=1;i<=n;i++){
			cnt[i]=0;
			qwq[i].clear();
			book[i].clear();
			awabook[i]=0;
			val[i]=0;
		}
		tot=0;
	}
	return 0;
}
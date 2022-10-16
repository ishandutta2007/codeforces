#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define maxn 8192
#define inf 1000000000
using namespace std;
int n,a[1000005];
int f[5005][maxn],g[5005][maxn];
vector<int> pos[5005];
int getnxt(int id,int qwq){
	int len=pos[id].size();
	if (len==0)return inf;
	if (pos[id][len-1]<=qwq)return inf;
	int l=0,r=len-1,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (pos[id][mid]>qwq)ans=mid,r=mid-1;
		else l=mid+1;
	}
	return pos[id][ans];
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]].push_back(i);
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	f[0][0]=g[0][0]=0;
	for (int i=1;i<=5000;i++){
		for (int j=0;j<maxn;j++){
			f[i][j]=min(f[i][j],getnxt(i,g[i-1][i^j]));
			g[i][j]=min(g[i-1][j],f[i][j]);
		}
	}
	int tot=0;
	for (int i=0;i<maxn;i++)
		if (g[5000][i]<=n)tot++;
	cout<<tot<<endl;
	for (int i=0;i<maxn;i++)
		if (g[5000][i]<=n)cout<<i<<' ';
	cout<<endl;
	return 0;
}
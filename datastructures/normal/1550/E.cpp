#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k,f[200005],nxt[17][200005];
char s[200005];
void upd(int &x,int y){
	if (x==-1||x>y)x=y;
	return;
}
bool check(int x){
	for (int i=0;i<k;i++){
		nxt[i][n+1]=n+1;
		int last=-1;
		for (int j=n;j>=1;j--){
			if (s[j]!='?'&&(s[j]-'a'!=i))last=-1;
			else if (last==-1)last=j;
			if (last!=-1&&j+x-1<=last)nxt[i][j]=j+x-1;
			else nxt[i][j]=nxt[i][j+1];
		}
	}
	memset(f,-1,sizeof(f));
	f[0]=0;
	for (int i=1;i<(1<<k);i++)
		for (int j=0;j<k;j++)
			if ((i&(1<<j))&&f[i^(1<<j)]!=-1&&f[i^(1<<j)]<=n)
				upd(f[i],nxt[j][f[i^(1<<j)]+1]);
	if (f[(1<<k)-1]<=n&&f[(1<<k)-1]!=-1)return 1;
	return 0;
}
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if (check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
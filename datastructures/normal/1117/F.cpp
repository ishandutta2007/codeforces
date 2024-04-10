#include <iostream>
#include <cstdio>
using namespace std;
int n,w,a[100005],qwq[20][20],awa[20][200005],ok[200005],f[200005];
int cnt[20],ans;
char s[100005];
void calc(int x,int y){
	for (int i=n;i>=1;){
		if (a[i]!=x){
			i--;
			continue;
		}
		int now=i-1,nows=((1<<w)-1);
		while(now>0&&a[now]!=x&&a[now]!=y){
			if (nows&(1<<a[now]))nows^=(1<<a[now]);
			now--;
		}
		if (now==0)break;
		if (a[now]==y)awa[x][nows]|=(1<<y);
		i=now;
	}
	return;
}
int main(){
	cin>>n>>w;
	scanf("%s",s+1);
	for (int i=1;i<=n;i++)a[i]=s[i]-'a',cnt[a[i]]++;
	for (int i=0;i<w;i++)
		for (int j=0;j<w;j++)
			cin>>qwq[i][j];
	for (int i=0;i<w;i++)
		for (int j=0;j<w;j++)
			calc(i,j);
	for (int i=0;i<w;i++)
		for (int j=(1<<w)-1;j>=0;j--)
			for (int k=0;k<w;k++)
				if (j&(1<<k))awa[i][j^(1<<k)]|=awa[i][j];
	for (int i=0;i<w;i++)
		for (int j=0;j<(1<<w);j++)
			awa[i][j]&=j;
	for (int i=0;i<(1<<w);i++){
		ok[i]=1;
		for (int j=0;j<w;j++){
			if (i&(1<<j)){
				for (int k=0;k<w;k++)
					if ((awa[j][i]&(1<<k))&&(qwq[j][k]==0))ok[i]=0;
			}
		}
	}
	f[(1<<w)-1]=1;
	for (int i=(1<<w)-1;i>=0;i--)
		for (int j=0;j<w;j++)
			if (ok[i^(1<<j)]&&(i&(1<<j)))f[i^(1<<j)]|=f[i];
	ans=n;
	for (int i=0;i<(1<<w);i++){
		if (f[i]==0)continue;
		int nowcnt=0;
		for (int j=0;j<w;j++)
			if (i&(1<<j))nowcnt+=cnt[j];
		ans=min(ans,nowcnt);
	}
	cout<<ans<<endl; 
	return 0;
}
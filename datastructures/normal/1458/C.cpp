#include <iostream>
#include <cstdio>
using namespace std;
int t,n,m,a[1005][1005],ans[1005][1005],pos[4],tag[4];
char s[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		scanf("%s",s+1);
		pos[1]=1,pos[2]=2,pos[3]=3;
		tag[1]=0,tag[2]=0,tag[3]=0;
		for (int i=1;i<=m;i++){
			if (s[i]=='R'){
				tag[pos[2]]++;
				if (tag[pos[2]]==n)tag[pos[2]]=0;
			}
			if (s[i]=='L'){
				tag[pos[2]]--;
				if (tag[pos[2]]<0)tag[pos[2]]=n-1;
			}
			if (s[i]=='D'){
				tag[pos[1]]++;
				if (tag[pos[1]]==n)tag[pos[1]]=0;
			}
			if (s[i]=='U'){
				tag[pos[1]]--;
				if (tag[pos[1]]<0)tag[pos[1]]=n-1;
			}
			if (s[i]=='I')swap(pos[2],pos[3]);
			if (s[i]=='C')swap(pos[1],pos[3]);
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=n;j++){
				int p[4];
				p[1]=i,p[2]=j,p[3]=a[i][j];
				p[1]+=tag[1];
				if (p[1]>n)p[1]-=n;
				p[2]+=tag[2];
				if (p[2]>n)p[2]-=n;
				p[3]+=tag[3];
				if (p[3]>n)p[3]-=n;
				int x=p[pos[1]],y=p[pos[2]],z=p[pos[3]];
				ans[x][y]=z;
			}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++)printf("%d ",ans[i][j]);
			puts("");
		}
	}
	return 0;
}
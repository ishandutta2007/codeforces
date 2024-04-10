#include <iostream>
#include <cstdio>
using namespace std;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	return x;
}
int n,k,m,x,pos[300005][5],len[300005];
char s[300005];
int dsu[600005],size[600005],num[600005],fg[600005],ans;
int find(int x){
	if (x==dsu[x])return x;
	return dsu[x]=find(dsu[x]);
}
int getval(int x){
	if (fg[x]==0)return size[x]-num[x];
	if (fg[x]==1)return num[x];
	return min(size[x]-num[x],num[x]);
}
void merge(int x,int y){
	x=find(x),y=find(y);
	if (x==y)return;
	ans-=getval(x),ans-=getval(y);
	dsu[x]=y;
	size[y]+=size[x];
	num[y]+=num[x];
	if (fg[y]==-1&&fg[x]!=-1)fg[y]=fg[x];
	size[x]=num[x]=0;
	fg[x]=-1;
	ans+=getval(y);
	return;
}
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	for (int i=1;i<=k;i++){
		m=read();
		for (int j=1;j<=m;j++){
			x=read();
			pos[x][++len[x]]=i;
		}
	}
	for (int i=1;i<=2*k;i++){
		dsu[i]=i,size[i]=1;
		if (i>k)num[i]=1;
		else num[i]=0;
		fg[i]=-1;
	}
	for (int i=1;i<=n;i++){
		if (len[i]==1){
			int x=find(pos[i][1]),y=find(pos[i][1]+k);
			ans-=getval(x);
			ans-=getval(y);
			if (s[i]=='0')fg[x]=0,fg[y]=1;
			if (s[i]=='1')fg[x]=1,fg[y]=0;
			ans+=getval(x);
			ans+=getval(y);
		}
		else{
			int x=pos[i][1],y=pos[i][2];
			if (s[i]=='0')merge(x,y+k),merge(x+k,y);
			if (s[i]=='1')merge(x,y),merge(x+k,y+k);
		}
		printf("%d\n",ans/2);
	}
	return 0;
}
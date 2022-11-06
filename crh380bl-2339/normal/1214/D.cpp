#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
string s[1000002];
int a[1000002],b[1000002],n,m;
int id(int x,int y){
	return m*x+y;
}
bool chk(int x,int y){
	return x>=0&&y>=0&&x<n&&y<m&&s[x][y]=='.';
}
void DFS1(int x,int y){
	a[id(x,y)]=1;
	if(chk(x+1,y)&&!a[id(x+1,y)])DFS1(x+1,y);
	if(chk(x,y+1)&&!a[id(x,y+1)])DFS1(x,y+1);
}
void DFS2(int x,int y){
	b[id(x,y)]=1;
	if(chk(x-1,y)&&!b[id(x-1,y)])DFS2(x-1,y);
	if(chk(x,y-1)&&!b[id(x,y-1)])DFS2(x,y-1);
}
int main(){
	int i,j,ans=3,t;
	scanf("%d%d",&n,&m);
	for(i=0;i<n;++i)cin>>s[i];
	DFS1(0,0);
	DFS2(n-1,m-1);
	for(i=0;i<n*m;++i)a[i]&=b[i];
//	for(i=0;i<n;++i){
//		for(j=0;j<m;++j)printf("%d ",a[id(i,j)]);puts("");
//	}
	if(!a[0]||!a[n*m-1]){
		puts("0");
		return 0;
	}
	for(i=1;i<n+m-2;++i){
		t=0;
		if(i<=m-1)for(j=0;j<=min(n-1,i);++j){
			if(a[id(j,i-j)])++t;
		}
		else for(j=m-1;i-j<=n-1&&j>=0;--j)if(a[id(i-j,j)])++t;
		ans=min(t,ans);
	}
	printf("%d\n",ans);
	return 0;
}
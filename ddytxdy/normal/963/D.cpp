#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define pb push_back
using namespace std;
const int N=1e5+50;
int n,t[N][26],cnt,q[N],l,r,fail[N],a[N],ll[N];char c[N],b[N];
vector<int>v[N],vv[N];
void insert(char *c,int id){
	ll[id]=strlen(c);int x=0;
	for(int i=0;i<ll[id];i++){
		int d=c[i]-'a';
		if(!t[x][d])t[x][d]=++cnt;
		x=t[x][d];
	}
	v[x].pb(id);
}
void build(){
	l=1;
	for(int i=0;i<26;i++)if(t[0][i])q[++r]=t[0][i];
	while(l<=r){
		int x=q[l++];
		for(int i=0;i<26;i++){
			int &y=t[x][i],z=t[fail[x]][i];
			if(!y)y=z;
			else {
				fail[y]=z,q[++r]=y;
				for(int k=0;k<v[z].size();k++)v[y].pb(v[z][k]);
			}
		}
	}
}
void ask(char *c){
	int len=strlen(c+1),x=0;
	for(int i=1;i<=len;i++){
		x=t[x][c[i]-'a'];
		for(int j=0;j<v[x].size();j++)vv[v[x][j]].pb(i);
	}
}
int main(){
	scanf("%s%d",c+1,&n);
	for(int i=1;i<=n;i++)scanf("%d%s",&a[i],b),insert(b,i);
	build();ask(c);
	for(int i=1;i<=n;i++){
		if(vv[i].size()<a[i]){puts("-1");continue;}
		int minn=1e9;
		for(int j=a[i]-1;j<vv[i].size();j++){
			if(vv[i][j]-vv[i][j-a[i]+1]<minn)minn=vv[i][j]-vv[i][j-a[i]+1];
		}
		printf("%d\n",minn+ll[i]);
	}
	return 0;
}
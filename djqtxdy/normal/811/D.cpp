#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 20160116
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}
const int Maxn=205;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
char c[Maxn][Maxn];
bool vis[Maxn][Maxn];
char s[5]="RLDU";
void dfs(int x,int y,int d1,int d2){
//	cout<<"pr"<<d1<<' '<<d2<<endl;
	vis[x][y]=true;
	if (c[x][y]=='F'){
		exit(0);
	}
	if (d1==-1 && c[x][y+1]!='*' && c[x][y-1]!='*'){
		printf("R\n");
		fflush(stdout);
		int nx,ny;
		scanf("%d %d",&nx,&ny);
		if (ny==y+1) d1=1; 
		else if (ny==y-1)d1=0;
		else if (c[x][y+1]=='.' || c[x][y+1]=='F') d1=0;
		else d1=1;
		dfs(nx,ny,d1,d2);
		//if (ny==y) return;
		printf("L\n");
		fflush(stdout);
		scanf("%d %d",&nx,&ny);
	}
	if (d2==-1 && c[x+1][y]!='*' && c[x-1][y]!='*'){
		printf("D\n");
		fflush(stdout);
		int nx,ny;
		scanf("%d %d",&nx,&ny);
		if (nx==x+1) d2=1; 
		else if (nx==x-1)d2=0;
		else if (c[x+1][y]=='.' || c[x+1][y]=='F') d2=0;
		else d2=1;
		dfs(nx,ny,d1,d2);
		//cout<<"fuck?";
		//if (nx==x) return;
		printf("U\n");
		fflush(stdout);
		scanf("%d %d",&nx,&ny);
	}
	if (d1!=-1){
		for (int i=0;i<2;i++){
			int nx=x+dx[i],ny=y+dy[i];
			//cout<<(int)(i^(d1^1))<<endl;
			if ((c[nx][ny]=='.' || c[nx][ny]=='F') && !vis[nx][ny]){
				printf("%c\n",s[i^(1^d1)]);
				fflush(stdout);
				scanf("%d %d",&nx,&ny);
				dfs(nx,ny,d1,d2);
				printf("%c\n",s[i^d1]);
				fflush(stdout);
				scanf("%d %d",&nx,&ny);
			}
		}
	}
	if (d2!=-1){
		for (int i=2;i<4;i++){
			int nx=x+dx[i],ny=y+dy[i];
			if ((c[nx][ny]=='.' || c[nx][ny]=='F') && !vis[nx][ny]){
				printf("%c\n",s[i^(1^d2)]);
				fflush(stdout);
				scanf("%d %d",&nx,&ny);
				dfs(nx,ny,d1,d2);
				printf("%c\n",s[i^d2]);
				fflush(stdout);
				scanf("%d %d",&nx,&ny);
			}
		}
	}
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",c[i]+1);
	}
//	cout<<c[4][1]<<endl;
	dfs(1,1,-1,-1);
	return 0;
}
/*
6 6
......
.****.
.*.**.
.*.**.
.****.
.....F
*/
/*
10 10
..********
F*********
**********
**********
**********
**********
**********
**********
**********
**********
*/
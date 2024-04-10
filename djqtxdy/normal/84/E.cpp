//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
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
#include <assert.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
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

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=55;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
int n,m,k;
int sx,sy,ex,ey;
char c[Maxn][Maxn];
int now[5];
int cc[55555][5];
bool canc[Maxn][Maxn];
int d[55555][5],dd[55555][5];
int cnt,kd,kdd;
int dist[Maxn][Maxn];
int val[55555];
void bfs(int x,int y){
	queue<pair<int,int> > q;
	dist[x][y]=0;
	q.push(mp(x,y));
	while (!q.empty()){
		pii coor=q.front();
		q.pop();
		for (int i=0;i<4;i++){
			pii nx={coor.first+dx[i],coor.second+dy[i]};
			if (nx.first>=0 && nx.second>=0 && nx.first<n && nx.second<m && dist[nx.first][nx.second]==20160116 && canc[nx.first][nx.second]){
				dist[nx.first][nx.second]=dist[coor.first][coor.second]+1;
				q.push(nx);
			}
		}
	}
}
string ans;
string noww;
bool vis[Maxn][Maxn];
void DD(int nx,int ny,int ex,int ey,int di){
	vector<pair<int,int> > avail,tmp;
	avail.push_back(mp(nx,ny));
	for (int i=di-1;i>=0;i--){
		char Mc='z';
		tmp.clear();
		for (int j=0;j<avail.size();j++){
			for (int kk=0;kk<4;kk++){
				int x=avail[j].first+dx[kk],y=avail[j].second+dy[kk];
				if (x>=0 && y>=0 && x<n && y<m && dist[x][y]==dist[avail[j].first][avail[j].second]-1){
					Mc=min(Mc,c[x][y]); 
				}
			}
		}
		for (int j=0;j<avail.size();j++){
			for (int kk=0;kk<4;kk++){
				int x=avail[j].first+dx[kk],y=avail[j].second+dy[kk];
				if (x>=0 && y>=0 && x<n && y<m && dist[x][y]==dist[avail[j].first][avail[j].second]-1){
					if (c[x][y]==Mc && !vis[x][y]){
						vis[x][y]=true;
						tmp.push_back(mp(x,y));
					}
				}
			}
		}
		avail=tmp;
		noww=noww+Mc;
	}
	if (ans=="" || ans>noww){
		ans=noww;
	} 
}
void Gao(int id){
	memset(canc,false,sizeof(canc));
	memset(vis,false,sizeof(vis));
	for (int i=0;i<n;++i){
		for (int j=0;j<m;j++){
			dist[i][j]=20160116;
		}
	}
	canc[sx][sy]=true;
	canc[ex][ey]=true;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			for (int l=0;l<k;l++){
				if (c[i][j]==dd[id][l]+'a'){
					canc[i][j]=true;
				}
			}
		}
	}
	bfs(ex,ey);
	DD(sx,sy,ex,ey,dist[sx][sy]);
}

int check(int id){
	memset(canc,false,sizeof(canc));
	for (int i=0;i<n;++i){
		for (int j=0;j<m;j++){
			dist[i][j]=20160116;
		}
	}
	canc[sx][sy]=true;
	canc[ex][ey]=true;
	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			for (int l=0;l<k;l++){
				if (c[i][j]==cc[id][l]+'a'){
					canc[i][j]=true;
				}
			}
		}
	}
	bfs(sx,sy);
	if (dist[ex][ey]<2500) return dist[ex][ey];
	return 0;
}
void go(int lvl,int x){
	if (lvl==k){
		for (int i=0;i<k;i++){
			cc[cnt][i]=now[i];
		}
		cnt++;
		return ;
	}
	for (int i=x;i<26;i++){
		now[lvl]=i;
		go(lvl+1,i+1);
	}
}
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for (int i=0;i<n;i++){
		scanf("%s",c[i]);
		for (int j=0;j<m;j++){
			if (c[i][j]=='S'){
				sx=i;
				sy=j;
			}
			else if (c[i][j]=='T'){
				ex=i;
				ey=j;
			}
		}
	}
	go(0,0);
	for (int i=0;i<cnt;i++){
		int tmp;
		if (tmp=check(i)){
			for (int j=0;j<k;j++){
				d[kd][j]=cc[i][j];
			}
			val[kd]=tmp;
			kd++;
		}
	}
	if (!kd){
		printf("-1\n");
		return 0;
	}
	int Mn=20160116;
	for (int i=0;i<kd;i++){
		Mn=min(Mn,val[i]); 
	}
//	cout<<Mn<<endl;
	for (int i=0;i<kd;i++){
		if (val[i]==Mn){
			for (int j=0;j<k;j++){
				dd[kdd][j]=d[i][j];
			}
			kdd++;
		}
	}
	for (int i=0;i<kdd;i++){
		noww.clear();
		Gao(i);
	}
	ans.pop_back();
	printf("%s\n",ans.c_str());
	return 0;
} 
/*
5 3 2
aaT
acc
bbb
bbc
cSb
*/
#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e6+10,P=1e9+7;
const int z[5][4]={{1,0},{0,1}};


int n,m;
string s[N],t[N];
int ans=2;
int cnt[N<<1];


/*void dfs(int x,int y){
	int u=x*m+y;
	t[u]=low[u]=++dfn;
	mk[u]=((x==(n-1))&&(y==(m-1)));
	rep(i,0,1) {
		int x1=x+z[i][0],y1=y+z[i][1];
		int v=x1*m+y1;
		if(x1>=n||y1>=m) continue;
		if(!t[v]) {
			dfs(x1,y1);
			mk[u]|=mk[v];
			low[u]=min(low[u],low[v]);
		} else {
			;
			;
			;
			;
		}
	}
}
*/







int main(){
	n=rd(),m=rd();
	rep(i,0,n-1) {
		cin>>s[i];
		t[i]=s[i];
	}
	ans=2;
	//if(n==1||m==1||s[0][1]=='#'||s[1][0]=='#') ans=1;
	rep(i,0,n-1) rep(j,0,m-1) if(i||j) if((!i||s[i-1][j]=='#') && (!j||s[i][j-1]=='#')) s[i][j]='#';
	drep(i,n-1,0) drep(j,m-1,0) if(i<n-1||j<m-1) if((i==n-1||t[i+1][j]=='#') && (j==m-1 || t[i][j+1]=='#' ) ) t[i][j]='#';
	rep(i,0,n-1) rep(j,0,m-1) if(s[i][j]!='#'&&t[i][j]!='#') cnt[i+j]++;
	if(s[n-1][m-1]=='#') ans=0;
	rep(i,1,n+m-3) ans=min(ans,cnt[i]);
	printf("%d\n",ans);
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define reg register
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=3e5+10,E=1e6;

int n,m;

int vis[N];
vector <int> Ans;



void Solve(){
	n=rd(),m=rd(); Ans.clear();
	rep(i,1,n*3) vis[i]=0;
	rep(i,1,m) {
		int u=rd(),v=rd();
		if(vis[u]||vis[v]) continue;
		vis[u]=vis[v]=1;
		Ans.push_back(i);
	}
	if((int)Ans.size()>=n) {
		puts("Matching");
		rep(i,0,n-1) printf("%d%c",Ans[i],(i==n-1)?'\n':' ');
		return;
	}
	int cnt=0;
	puts("IndSet");
	rep(i,1,n*3) if(!vis[i]) {
		cnt++;
		printf("%d%c",i,cnt==n?'\n':' ');
		if(cnt==n) break;
	}
}




int main(){
	rep(kase,1,rd()) Solve();
}
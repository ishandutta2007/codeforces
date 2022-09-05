#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int x = 15, y = 51, z = 85, inf = 36;
string val[266][3];bool vis[266][3];int n=255;//[0..n-1][0..2]
inline bool cmp(string a,string b){
	if(a.size()!=b.size())return a.size()<b.size();
	for(int l=a.size(),i=0;i<l;i++)if(a[i]!=b[i])return a[i]<b[i];return 0;
}
inline void upd(string &a,string b){if(cmp(b,a))a=b;}
int main() {//freopen("1.in","r",stdin);
	rep(i,0,n)rep(j,0,2)rep(k,1,inf)val[i][j]=val[i][j]+'z';
	val[x][2]='x';val[y][2]='y';val[z][2]='z';
	rep(t,1,256*3){
		int i=-1,tp=-1;
		rep(a,0,n)rep(b,0,2)if(!vis[a][b]&&(i==-1||cmp(val[a][b],val[i][tp])))i=a,tp=b;
		vis[i][tp]=1;assert(val[i][tp].size()<inf);
		string now=val[i][tp];//printf("%d %d:%d\n",i,tp,val[i][tp].size());
		if(tp==0){upd(val[i][2],'('+now+')');rep(j,0,n)upd(val[i|j][0],now+'|'+val[j][1]);}
		if(tp==1){
			upd(val[i][0],now);rep(j,0,n)upd(val[i&j][1],now+'&'+val[j][2]);
			rep(j,0,n)upd(val[j|i][0],val[j][0]+'|'+now);
		}
		if(tp==2){
			upd(val[i^n][2],'!'+now);upd(val[i][1],now);
			rep(j,0,n)upd(val[j&i][1],val[j][1]+'&'+now);
		}
	}
//	cout<<val[15][0]<<' '<<val[17][1]<<endl;
	int q;read(q);
	while(q--){
		char t[10];scanf("%s",t+1);
		int s=0;rep(i,1,8)s=s*2+t[i]-'0';
		string ans=val[s][0];upd(ans,val[s][1]);upd(ans,val[s][2]);//WA1
		cout<<ans<<endl;
	}
	return 0;
}
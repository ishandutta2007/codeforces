#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int mod=1e9+7;
const int N=25005;
int fail[N],t[N][10],f[55][N];
char s[N],x[N],y[N];
int n,d,m,sz=2;

void ins(char s[],int len){
	int o=1;
	rep(i,1,len-1){
		if(!t[o][s[i]-'0'])t[o][s[i]-'0']=++sz;
		o=t[o][s[i]-'0'];
	}
	t[o][s[len]-'0']=2;
}

void build(){
	static int q[N];
	int l=0,r=0; fail[1]=1;
	REP(k,10){
		if(t[1][k])q[r++]=t[1][k],fail[t[1][k]]=1;
		else t[1][k]=1;
		t[2][k]=2;
	}
	while(l<r){
		int u=q[l++];
		REP(k,10)
			if(!t[u][k])t[u][k]=t[fail[u]][k];
			else if(t[u][k]!=2){
				fail[t[u][k]]=t[fail[u]][k];
				q[r++]=t[u][k];
			}
	}
}

inline void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int solve(char c[]){
	int now=1,res=0;
	rep(i,1,d){
		memset(f[i-1],0,sizeof f[i-1]);
		f[i-1][now]=1;
		rep(j,i,d){
			memset(f[j],0,sizeof f[j]);
			rep(s,1,sz)if(f[j-1][s]){
				int lim=(j==i?c[j]-'0'-1+(i==d):9);
				rep(k,0,lim)
					add(f[j][t[s][k]],f[j-1][s]);
			}
		}
		add(res,f[d][2]);
		now=t[now][c[i]-'0'];
	}
	return res;
}

int main(){
	scanf("%s%s%s",s+1,x+1,y+1);
	n=strlen(s+1);d=strlen(x+1),m=d/2;
	rep(i,0,n-m)ins(s+i,m);
	build();
	int k=d;while(x[k]=='0')x[k--]='9';x[k]--;
	printf("%d\n",(solve(y)-solve(x)+mod)%mod);
	return 0;
}
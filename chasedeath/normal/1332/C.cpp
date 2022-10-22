#include<bits/stdc++.h> 
using namespace std;

#define reg register
typedef long long ll;
typedef unsigned int ui;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

#define pb push_back
template <class T> inline void cmin(T &a,T b){ if(a>b) a=b; }
template <class T> inline void cmax(T &a,T b){ if(a<b) a=b; }

char IO;
int rd(){
	int s=0;
	int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,P=998244353;

int n,m;
char s[N];
int fa[N],sz[N][26];

int Find(int x){ return fa[x]==x?x:fa[x]=Find(fa[x]); }
void Union(int x,int y) {
	x=Find(x),y=Find(y);
	if(x==y) return;
	//cout<<"#"<<x<<' '<<y<<endl;
	fa[x]=y;
	rep(i,0,25) sz[y][i]+=sz[x][i];
}


int main(){
	rep(kase,1,rd()) {
		n=rd(),m=rd();
		scanf("%s",s+1);
		rep(i,1,n) {
			fa[i]=i;
			rep(j,0,25) sz[i][j]=0;
			sz[i][s[i]-'a']=1;
		}
		rep(i,1,n/2) Union(i,n-i+1);
		rep(i,1,n-m) Union(i,i+m);
		int ans=0;
		//rep(i,1,n) cout<<Find(i)<<' '; puts("");
		rep(i,1,n) if(Find(i)==i) {
			int ma=0;
			rep(j,0,25) if(sz[i][j]) {
				ans+=sz[i][j],cmax(ma,sz[i][j]);
			}
			ans-=ma;
		}
		printf("%d\n",ans);
	}
}
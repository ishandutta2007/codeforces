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
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 16005;//1600*10
int n,S,T,a[N];

int ch[N][10],fail[N],dfn[N],num,trans[N][10],tot;Vi endpos[N],e[N];
void ins(int l, int r, int w){
	int now=0;
	rep(i,l,r){
		if(!ch[now][a[i]])ch[now][a[i]]=++tot;
		now=ch[now][a[i]];
	}
	endpos[now].pb(w);
}
void getdfn(int u){
	dfn[++num]=u;rep(i,0,SZ(e[u])-1)getdfn(e[u][i]);
}
void buildfail(){
	static int q[N];
	int f=0,r=0;rep(i,0,9)if(ch[0][i]){
		q[r++]=ch[0][i];
	}
	while(f!=r){
		int u=q[f++];
		rep(i,0,9)if(ch[u][i]){
			int v=ch[u][i],x=fail[u];
			while(x&&!ch[x][i])x=fail[x];
			fail[v]=ch[x][i];q[r++]=v;
		}
	}
	rep(i,0,tot)rep(j,0,9){
		int u=i;while(u&&!ch[u][j])u=fail[u];trans[i][j]=ch[u][j];
	}
	rep(i,1,tot)e[fail[i]].pb(i);getdfn(0);
	/*rep(i,0,tot)rep(j,0,9)if(trans[i][j]){
		printf("%d %d:%d %d\n",i,j,ch[i][j],trans[i][j]);
	}*/
//	rep(i,0,tot)rep(j,0,9)ch[i][j]=trans[i][j];
}

struct INI{
char s[N],t[N];
void dfs(int dep, bool A, bool B){
	if(A&&B||dep>S){
		int bg=0;rep(i,1,dep-1)if(a[i]){bg=i;break;}
	//	rep(i,bg,dep-1)printf("%d",a[i]);printf(":%d\n",S-dep+1);
		ins(bg,dep-1,S-dep+1);
		return;
	}
	rep(i,0,9)if((A||'0'+i>=s[dep])&&(B||'0'+i<=t[dep])){
		a[dep]=i;dfs(dep+1,A|('0'+i>s[dep]),B|('0'+i<t[dep]));
	}
}
void init(){
	scanf("%s%s",s+1,t+1);
	S=strlen(s+1);T=strlen(t+1);int del=T-S;
	per(i,S,1)s[del+i]=s[i];rep(i,1,del)s[i]='0';S=T;
	dfs(1,0,0);rep(i,1,tot)if(SZ(endpos[i]))sort(endpos[i].begin(),endpos[i].end());
	buildfail();
}
}ini;

int lst[2002][N],cnt[N],zid[N];int ok[N][10],sz[N];
int s[N],len,pos[N],cost[N];
inline int encode(int x, int y){return 10*x+y;}
int main() {
	ini.init();
	memset(zid,-1,sizeof(zid));read(n);zid[0]=0;//[0..tot]
	
//	int q=0,qaq=0;
	
	cerr<<tot<<endl;
	
	double tst1,tst2,tst3;
//	printf("%.6lf\n",1.0*clock()/CLOCKS_PER_SEC);
	rep(time,1,n+1){
		tst1-=clock();
		memset(sz,0,sizeof(sz));
		memset(pos,-1,sizeof(pos));
		len=0;rep(i,0,tot)if(zid[i]>=0)pos[zid[i]]=i;
		per(i,tot,0)if(pos[i]>=0)s[++len]=pos[i];
		static int buc[2002],t[N];memset(buc,0,sizeof(buc));
		rep(i,1,len)buc[cnt[s[i]]%2000]++;
		rep(i,1,2000)buc[i]+=buc[i-1];
		per(i,len,1)t[buc[cnt[s[i]]%2000]--]=s[i];
		memset(buc,0,sizeof(buc));
		rep(i,1,len)buc[cnt[t[i]]/2000]++;
		rep(i,1,2000)buc[i]+=buc[i-1];
		per(i,len,1)s[buc[cnt[t[i]]/2000]--]=t[i];
		
		tst1+=clock();
		
		rep(i,1,len-1)assert(cnt[s[i]]!=cnt[s[i+1]]?cnt[s[i]]<cnt[s[i+1]]:zid[s[i]]>zid[s[i+1]]);
		
		if(time>n){//cerr<<qaq<<endl;
		//	printf("%.6lf\n",tst1/CLOCKS_PER_SEC);
		//	printf("%.6lf\n",tst2/CLOCKS_PER_SEC);
		//	printf("%.6lf\n",tst3/CLOCKS_PER_SEC);
			int u=s[len];
			printf("%d\n",cnt[u]);Vi res;
			per(i,n,1)res.pb(lst[i][u]%10),u=lst[i][u]/10;
			per(i,SZ(res)-1,0)printf("%d",res[i]);puts("");
			return 0;
		}
		
		static int Cnt[N],Zid[N];
		memset(Zid,-1,sizeof(Zid));
		memset(cost,0,sizeof(cost));
		tst3-=clock();
		rep(j,1,num){//dfn[1..num] not 0..tot !!!!!!!!!!!!
			int i=dfn[j];cost[i]=cost[fail[i]];//fail[i]<i 
			rep(j,0,SZ(endpos[i])-1)cost[i]+=endpos[i][j]<=n-time;
		}
		tst3+=clock();
		tst2-=clock();
		per(i,len,1)rep(j,0,9){//s[i]
			if(Zid[trans[s[i]][j]]==-1){
			//	printf("trans %d %d %d %d %d\n",time,s[i],j,trans[s[i]][j],cnt[s[i]]+cost[trans[s[i]][j]]);
				ok[s[i]][sz[s[i]]++]=trans[s[i]][j];
				Zid[trans[s[i]][j]]=0;
				lst[time][trans[s[i]][j]]=encode(s[i],j);
				Cnt[trans[s[i]][j]]=cnt[s[i]]+cost[trans[s[i]][j]];
			}
		}
		int now=0;
		rep(i,0,tot)if(pos[i]>=0){
			int u=pos[i];rep(j,0,sz[u]-1)Zid[ok[u][j]]=now++;
		}
		tst2+=clock();
		rep(i,0,tot)
			if(Zid[i]>=0)zid[i]=Zid[i],cnt[i]=Cnt[i];
			else zid[i]=-1,cnt[i]=0;
		
	//	q=trans[q][time==2?0:1];qaq+=cost[q];printf("<%d %d>\n",time,cost[q]);
	}
	//trans[] ch[] 
	return 0;
}
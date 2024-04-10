#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORD(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
bitset<777> u[777];
char c[10000010],s[10000010];
bool v[777],lm[777],rm[777];
int L[777],m,l[777],C,ans,R[777],r[777],fail[10000010],n,LAS[10000010],las[10000010],q[10000010],tot,son[10000010][2],id[10000010];
void ins(int l,int r,int x){
	int now=0;
	FOR(i,l,r){
		if (!son[now][c[i]-'a']) son[now][c[i]-'a']=++tot;
		now=son[now][c[i]-'a'];
	}
	id[now]=x;
}
void build(){
	int he=0,ta=1;
	q[1]=0;
	while (he!=ta){
		int x=q[++he];
		if (id[fail[x]]) las[x]=fail[x];
		else las[x]=las[fail[x]];
		if (id[x]) LAS[x]=x;
		else LAS[x]=LAS[fail[x]];
		FOR(i,0,1){
			if (!son[x][i]) continue;
			int y=son[x][i];
			q[++ta]=y;
			if (!x) continue;
			int t=fail[x];
			while (t && !son[t][i]) t=fail[t];
			if (son[t][i]) t=son[t][i];
			fail[y]=t;
		}
	}
}
bool fnd(int x){
	FOR(i,1,n){
		if (!u[x][i] || v[i]) continue;
		v[i]=1;
		if (R[i]==-1 || fnd(R[i])){
			R[i]=x;
			return 1;
		}
	}
	return 0;
}
void dfs(int x){
	if (v[x]) return;
	v[x]=1;
	rm[x]=1;
	FOR(i,1,n){
		if (!u[x][i]) continue;
		lm[i]=1;
		if (R[i]) dfs(R[i]);
	}
}
int main(){
	scanf("%d",&n);
	FOR(i,1,n){
		scanf("%s",s+1);
		m=strlen(s+1);
		l[i]=C+1;
		FOR(j,1,m) c[++C]=s[j];
		r[i]=C;
	}
	FOR(i,1,n) ins(l[i],r[i],i);
	build();
	FOR(i,1,n){
		int now=0;
		FOR(j,l[i],r[i]){
			now=son[now][c[j]-'a'];
			if (j==r[i]){
				if (id[las[now]]) u[i][id[las[now]]]=1;
			}
			else{
				if (id[LAS[now]]) u[i][id[LAS[now]]]=1;
			}
		}
	}
	FOR(i,1,n)
		FOR(j,1,n)
			if (u[j][i]) u[j]|=u[i];
	/*
	FOR(i,1,n){
		FOR(j,1,n)
			if (u[i][j]) printf("1 ");
			else printf("0 ");
		puts("");
	}
	*/
	FOR(i,1,n) R[i]=-1;
	FOR(i,1,n){
		FOR(j,1,n) v[j]=0;
		fnd(i);
	}
	FOR(i,1,n) L[i]=-1;
	FOR(i,1,n) if (R[i]!=-1) L[R[i]]=i;
	FOR(i,1,n) if (R[i]==-1) ++ans;
	cout<<ans<<endl;
	FOR(i,1,n) v[i]=0;
	FOR(i,1,n) if (L[i]==-1) dfs(i);
	FOR(i,1,n) if (!(!rm[i] || lm[i])) printf("%d ",i);
	return 0;
}
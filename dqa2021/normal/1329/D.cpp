#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
//#include<assert.h>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G

int n,m; int minid; char s[200010]; int S;
int btot,bmax,c[26],cbin[200010];
void checkmax(){while (!cbin[bmax]) bmax--;}
void del(int x){cbin[c[x]]--; c[x]--; cbin[c[x]]++;}
int prelen;
struct Stk{
	int l,r,len;
}stk[200010]; int stktop;
void ins(int x,bool flg){
	if(!flg){
		if (stktop&&stk[x].l!=stk[stktop].r){
			stk[stktop].r=stk[x].r,stk[stktop].len+=stk[x].len;
			prelen+=stk[x].len;
			if (S==1&&stktop>1&&x<m&&stk[stktop].l==stk[stktop-1].r&&stk[stktop].l!=stk[stktop].r&&bmax*2<btot||
				S==2&&stktop>1&&x<m&&stk[stktop].l==stk[stktop-1].r&&((stk[stktop].l==minid)^(stk[stktop].r==minid))){
				btot-=2; del(stk[stktop].l); del(stk[stktop].r); checkmax();
				printf("%d %d\n",prelen-stk[stktop].len+1,prelen);
				prelen-=stk[stktop--].len;
			}
		}
		else{
			stk[++stktop]=stk[x];
			prelen+=stk[x].len;
		}
		return;
	}
	btot-=2; del(stk[x].l); del(stk[x].r); checkmax();
	printf("%d %d\n",prelen+1,prelen+stk[x].len);
}
void init(){
	btot=0; memset(c,0,sizeof c); memset(cbin,0,n*sizeof(int)); stktop=0;
}
void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	int lst=1;
	for (int i=2;i<=n;i++){
		if (s[i]==s[i-1]){
			stk[++stktop]=(Stk){s[lst]-'a',s[i-1]-'a',i-lst};
			lst=i;
			btot++; c[s[i]-'a']++;
		}
	}
	stk[++stktop]=(Stk){s[lst]-'a',s[n]-'a',n-lst+1};
	for (int i=0;i<26;i++) cbin[c[i]]++; bmax=n; checkmax();
	printf("%d\n",max(btot+1>>1,bmax)+1);
	m=stktop; stktop=0; prelen=0; S=1;
//	for (int i=1;i<=m;i++) printf("stk %d: %d %d %d\n",i,stk[i].l,stk[i].r,stk[i].len);
	for (int i=1;i<=m;i++){
		ins(i,stktop&&i<m&&stk[i].l==stk[stktop].r&&stk[i].l!=stk[i].r&&bmax*2<btot);
	}
//	puts("----------");
	minid=-1;
	for (int i=0;i<26;i++) if (c[i]==bmax) minid=i;
	m=stktop; stktop=0; prelen=0; S=2;
//	for (int i=1;i<=m;i++) printf("stk %d: %d %d %d\n",i,stk[i].l,stk[i].r,stk[i].len);
	for (int i=1;i<=m;i++){
		ins(i,stktop&&i<m&&stk[i].l==stk[stktop].r&&((stk[i].l==minid)^(stk[i].r==minid)));
	}
	for (int i=1;i<=stktop;i++) printf("1 %d\n",stk[i].len);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}
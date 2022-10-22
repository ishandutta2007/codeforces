#include<iostream>
#include<cstring>
#include<cassert>
#include<cmath>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<bitset>
#include<cstdio>
#include<algorithm>
using namespace std;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define rep(i,n) REP(i,1,n)
#define rep0(i,n) REP(i,0,n-1)
#define repG(i,x) for(int i=pos[x];~i;i=e[i].next)
#define ll long long
#define db double
#define F fflush(stdout)
const int N=107;
const int INF=1e9+7;
int n,num=0;
char s[N];
struct edge{int v,next,c;}e[N*2];
int d1[N],d2[N],b[N][N][26],t[N],pos[N],ss[26],Ans[N],o1[26],o2[26],o3[26];
void add(int x,int y,int c){e[num]=(edge){y,pos[x],c}; pos[x]=num++;}
void check(int l,int r,int *o){
	printf("? %d %d\n",l,r);
	F;
	int g=r-l+1;
	memset(b,0,sizeof(b));
	memset(t,0,sizeof(t));
	rep0(j,26)o[j]=0;
	rep(i,g*(g+1)/2){
		scanf("%s",s+1);
		int q=strlen(s+1);
		t[q]++;
		rep(j,q)b[q][t[q]][s[j]-'a']++;
		if(q==1)o[s[1]-'a']++;
	}
	rep(i,(g+1)/2){
		memset(ss,0,sizeof(ss));
		rep(j,t[g-i])rep0(k,26)ss[k]+=b[g-i][j][k];
		rep(j,i-1){
			ss[d1[j]]-=j;
			ss[d2[j]]-=j;
		}
		int id1=-1,id2=-1;
		rep0(j,26){
			if(ss[j]%(i+1)!=0){
				if(~id1)id2=j;
				else id1=j;
			}
		}
		if(id2<0){
			if(id1<0){
				rep0(j,26){
					int q=b[g][1][j],mx=0;
					rep(k,t[g-1])mx=max(mx,b[g-1][k][j]);
					if(q!=mx)id1=j;
				}
			}
			Ans[i+(l-1)]=Ans[g-i+1+(l-1)]=id1;
			d1[i]=d2[i]=id1;
		}
		else{
			add(i+(l-1),g-i+1+(l-1),id1+id2);
			add(g-i+1+(l-1),i+(l-1),id1+id2);
			d1[i]=id1;
			d2[i]=id2;
		}
	}
}
int main(){
	scanf("%d",&n);
	if(n<=3){
		rep(i,n){
			printf("? %d %d\n",i,i);
			F;
			char a[4]; scanf("%s",a);
			Ans[i]=a[0]-'a';
		}
		printf("! ");
		rep(i,n)putchar('a'+Ans[i]);
		puts("");
		return 0;
	}
	memset(pos,-1,sizeof(pos));
	memset(Ans,-1,sizeof(Ans));
	if(n&1){
		check(1,n,o1);
		check(1,(n+1)/2,o2);
		check((n+1)/2+1,n,o3);
	}
	else{
		check(1,n,o1);
		check(1,n/2+1,o2);
		check(n/2+1,n,o3);
		rep0(k,26)if(o1[k]!=o2[k]+o3[k])Ans[n/2+1]=k;
	}
	rep(i,n){
		rep(j,n){
			if(Ans[j]<0)continue;
			repG(k,j)if(Ans[e[k].v]<0)Ans[e[k].v]=e[k].c-Ans[j];
		}
	}
	printf("! ");
	rep(i,n)putchar('a'+Ans[i]);
	puts("");
	return 0;
}
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
const int N=1e5+7;
const int INF=1e9+7;
int T,n,x0,y0;
char s[N];
int a[26],b[N];
bool check(int nw){
	if(b[nw-1]==x0&&b[nw]==y0)return 0;
	if(x0!=y0){
		if(b[nw]==x0&&a[y0]&&a[x0]+a[y0]==n-nw)return 0;
		return 1;
	}
	int w0=n-nw-a[x0],w1=a[x0];
	if(b[nw]!=x0)w0++;
	return w0>=w1;
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(a,0,sizeof(a));
		scanf("%s",s+1);
		n=strlen(s+1);
		rep(i,n)a[s[i]-'a']++;
		int s1=0,s2=INF;
		rep0(i,26){
			if(a[i])s1++;
			if(a[i]==1)s2=min(s2,i);
		}
		if(s1==1){
			rep0(i,26)rep(j,a[i])putchar('a'+i);
			puts("");
			continue;
		}
		if(s2<26){
			putchar('a'+s2);
			a[s2]--;
			rep0(i,26)rep(j,a[i])putchar('a'+i);
			puts("");
			continue;
		}
		x0=-1;
		rep0(i,26){
			if(!a[i])continue;
			rep0(j,26){
				if(!a[j])continue;
				if(i!=j){
					x0=i;
					y0=j;
					break;
				}
				int r=a[i]-2;
				if(n-2-r>=r){
					x0=i;
					y0=j;
					break;
				}
			}
			if(~x0)break;
		}
		b[1]=x0;
		b[2]=y0;
		a[x0]--;
		a[y0]--;
		REP(i,3,n){
			rep0(j,26){
				if(a[j]){
					b[i]=j;
					a[j]--;
					if(check(i)){
						break;
					}
					a[j]++;
				}
			}
		}
		rep(i,n)putchar('a'+b[i]);
		puts("");
	}
	return 0;
}
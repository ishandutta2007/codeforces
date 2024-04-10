#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
using namespace std;
const int N=1e6+6; 
int a[N],s[N],tg[30],la[30];
int main(){
	int T; scanf("%d",&T);
	while (T--){
		char s[N]; scanf("%s",s); int n=strlen(s);
		rep(i,1,n) a[i]=s[i-1]-'a'+1;
		rep(j,1,26) tg[j]=false;
		rep(i,1,n) tg[a[i]]=true;
		int c=0; rep(j,1,26) c+=tg[j],tg[j]=0;
		int b=0;
		rep(t,1,c){
			rep(j,1,26) la[j]=0;
			s[n+1]=0;
			per(i,n,b+1){
				s[i]=s[i+1]+(!tg[a[i]]&&!la[a[i]]);
				la[a[i]]=i;
			}
			per(j,26,1)
				if (!tg[j]&&la[j]&&s[la[j]]>=c-t+1){
					b=la[j],tg[j]=true; putchar('a'+j-1);
					break;
				}
		}
		putchar('\n');
	}
	return 0;
}
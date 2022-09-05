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
const int N = 26666;
char ans[N],s[N];
multiset<Vi>Set;
int buc[N][27];
int main() {
	int n;read(n);
	if(n==1){
		printf("? %d %d\n",1,n);fflush(stdout);
		scanf("%s",s+1);printf("! %s\n",s+1);
		return 0;
	}
	int p=(n+1)/2;if(p==1)p++;
	printf("? %d %d\n",1,p);fflush(stdout);
	rep(j,1,p*(p+1)/2){
		scanf("%s",s+1);int len=strlen(s+1);
		Vi a(26,0);
		rep(i,1,len)a[s[i]-'a']++;
		Set.insert(a);
	}
	
	printf("? %d %d\n",2,p);fflush(stdout);
	rep(j,1,p*(p-1)/2){
		scanf("%s",s+1);int len=strlen(s+1);
		Vi a(26,0);
		rep(i,1,len)a[s[i]-'a']++;
		Set.erase(Set.find(a));
	}
	for(multiset<Vi>::iterator it=Set.begin();it!=Set.end();it++){
		Vi b=*it;
		int tot=0;rep(i,0,25)tot+=b[i];
		rep(i,0,25)buc[tot][i]=b[i];
	}
	rep(i,1,p)rep(j,0,25)if(buc[i][j]!=buc[i-1][j])ans[i]='a'+j;
	
	memset(buc,0,sizeof(buc));
	printf("? %d %d\n",1,n);fflush(stdout);
	rep(j,1,n*(n+1)/2){
		scanf("%s",s+1);int len=strlen(s+1);
		rep(i,1,len)buc[len][s[i]-'a']++;
	}
	
	for(int l=n-1;l+1>p;l--){
		rep(i,1,n-l+1){
		//	rep(j,i,n)buc[l][ans[j]-'a']--;
			rep(j,0,25)buc[l][j]-=buc[n][j];
			rep(j,1,i-1)buc[l][ans[j]-'a']++;
			rep(j,i+l,n)if(j>l+1)buc[l][ans[j]-'a']++;
		}
		rep(j,0,25)if(buc[l][j]){ans[l+1]='a'+j;break;}
	}
	
	printf("! ");rep(i,1,n)printf("%c",ans[i]);puts("");
	fflush(stdout);
	
	return 0;
}
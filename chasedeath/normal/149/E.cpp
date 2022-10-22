#include<cstdio> 
#include<cstring> 
#include<cctype>
#include<algorithm>
using namespace std;



#define reg register
typedef long long ll;
typedef unsigned ui;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0;
	while(!isdigit(IO=getchar()));
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return s;
}


const ll P=19260817,K=5567891;
const ll P1=1e9+13,K1=6550879;
const int N=1e5+10;

int n,m;
char s[N],p[N];

int nxt[N];
int ans;
int ma[N];

int main() {
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(t,1,rd()) {
		scanf("%s",p+1);
		int l=strlen(p+1);
		if(l==1) continue;
		rep(i,2,l) {
			int j=nxt[i-1];
			while(j&&p[i]!=p[j+1]) j=nxt[j];
			if(p[i]==p[j+1]) j++;
			nxt[i]=j;
		}
		int j=0;
		rep(i,1,n){
			while(j && s[i]!=p[j+1]) j=nxt[j];
			if(s[i]==p[j+1]) j++;
			ma[i]=max(ma[i-1],j);
		}
		rep(i,1,l/2) swap(p[i],p[l-i+1]);
		rep(i,2,l) {
			int j=nxt[i-1];
			while(j&&p[i]!=p[j+1]) j=nxt[j];
			if(p[i]==p[j+1]) j++;
			nxt[i]=j;
		}
		j=0;
		drep(i,n,1){
			while(j && s[i]!=p[j+1]) j=nxt[j];
			if(s[i]==p[j+1]) j++;
			if(j+ma[i-1]>=l) {
				ans++;
				break;
			}
		}
	}
	printf("%d\n",ans);
}
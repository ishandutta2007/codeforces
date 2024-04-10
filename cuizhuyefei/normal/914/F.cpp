#include<cstdio>
#include<cstring>
#include<bitset>
#define rep(i,a,b) for (int i=a; i<=b; i++)
using namespace std;
const int N = 100020;
char s[N],t[N];
int n,q;
bitset<100002> a[27],All,ans;
int main() { //freopen("1.in","r",stdin);
	scanf("%s",s+1); n=strlen(s+1);
	rep(i,0,25) rep(j,1,n) a[i][j]=(s[j]=='a'+i);
	rep(i,1,n) All[i]=1;
	scanf("%d",&q);
	while (q--) {
		int op; scanf("%d",&op);
		if (op==1) {
			int i; char c[3]; scanf("%d%s",&i,c);
			a[s[i]-'a'][i]=0; s[i]=c[0]; a[s[i]-'a'][i]=1;
		}
		else {
			int l,r,len; scanf("%d%d%s",&l,&r,t+1); len=strlen(t+1);
			l=l+len-1; if (l>r) {puts("0"); continue;}
			ans=All;
			rep(i,1,len) ans&=a[t[i]-'a']<<len-i;
		//	rep(i,1,n) printf("%d",(int)ans[i]); puts("");
			printf("%d\n",int((ans>>l).count()-(ans>>r+1).count()));
		}
	}
	return 0;
}
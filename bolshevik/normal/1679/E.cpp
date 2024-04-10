#include<cstdio>
#include<cstring>
using namespace std;
const int o=1<<18,MOD=998244353;
int n,q,a[18][o],pw[18][o],tot;char s[o],t[o];
int main(){
	scanf("%d%s%d",&n,s+1,&q);
	for(int i=1;i<=n;++i) tot+=(s[i]=='?');
	for(int i=1;i<18;++i) for(int j=pw[i][0]=1;j<=tot;++j) pw[i][j]=pw[i][j-1]*1ll*i%MOD;
	for(int j=1;j<18;++j) for(int i=2;i<=2*n;++i) for(int l=i/2,S=0,r,z=tot;l;--l)
		if((r=i-l)>n) break;
		else if(s[l]=='?'&&s[r]=='?') a[j][S]=(a[j][S]+pw[j][z-=(l!=r)])%MOD;
		else if(s[l]=='?'||s[r]=='?') S|=1<<(s[l]+s[r]-'?'-97),a[j][S]=(a[j][S]+pw[j][--z])%MOD;
		else if(s[l]==s[r]) a[j][S]=(a[j][S]+pw[j][z])%MOD;else break;
	for(int i=1;i<18;++i) for(int md=1;md<o;md<<=1) for(int j=0;j<o;j+=md<<1)
		for(int k=0;k<md;++k) a[i][md+j+k]=(a[i][md+j+k]+a[i][j+k])%MOD;
	for(int len,S=0;q--;printf("%d\n",a[len][S]),S=0){
		scanf("%s",t+1);len=strlen(t+1);
		for(int i=1;i<=len;++i) S|=1<<(t[i]-'a');
	}
	return 0;
}
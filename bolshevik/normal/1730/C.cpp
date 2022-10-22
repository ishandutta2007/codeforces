#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int T,n,t,cnt;char s[o],mn[o],a[o];
int main(){
	for(scanf("%d",&T);T--;putchar('\n'),cnt=0){
		scanf("%s",s+1);n=strlen(s+1);
		mn[n+1]=99;
		for(int i=n;i;--i) mn[i]=min(s[i],mn[i+1]);
		for(int i=1;i<=n;++i) if(s[i]>mn[i]) a[++cnt]=min(s[i]+1,(int)'9');
		sort(a+1,a+cnt+1);
		for(int i=t=1;i<=n;++i) if(s[i]<=mn[i]){
			for(;t<=cnt&&a[t]<=s[i];++t) putchar(a[t]);
			putchar(s[i]);
		}
		for(;t<=cnt;++t) putchar(a[t]);
	}
	return 0;
}
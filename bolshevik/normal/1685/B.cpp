#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int o=2e5+10;
int T,a,b,c,d,n,cnt[70],v2[o],v3[o],s1,c2,c3;char s[o];
int main(){
	for(scanf("%d",&T);T--;cnt['A']=cnt['B']=s1=c2=c3=0){
		scanf("%d%d%d%d%s",&a,&b,&c,&d,s+1);n=strlen(s+1);
		s[0]=s[1];s[n+1]=s[n];
		for(int i=1;i<=n;++i) ++cnt[s[i]];
		if(cnt['A']!=a+c+d||cnt['B']!=b+c+d){printf("NO\n");continue;}
		for(int i=1,j=0;i<=n+1;++i)
			if(s[i]==s[i-1]){
				if(j) if(j&1) s1+=j/2;else if(s[i-j]=='A') v2[++c2]=j/2;else v3[++c3]=j/2;
				j=1;
			}
			else ++j;
		sort(v2+1,v2+c2+1);sort(v3+1,v3+c3+1);
		for(int i=1;i<=c2;++i) if(v2[i]<=c) c-=v2[i];else d-=v2[i]-c-1,c=0;
		for(int i=1;i<=c3;++i) if(v3[i]<=d) d-=v3[i];else c-=v3[i]-d-1,d=0;
		printf((s1<max(c,0)+max(d,0))?"NO\n":"YES\n");
	}
	return 0;
}
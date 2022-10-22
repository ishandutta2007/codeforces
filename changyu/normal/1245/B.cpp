#include<cstdio>
const int N=103;
int n,a[N],c,r,p,s;char t[N],ans[N];
signed main()
{
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d%d%s",&n,&r,&p,&s,t+1);
	c=0;
	for(int i=1;i<=n;i++){
	  ans[i]=0;
	  switch(t[i]){
		case'R':if(p)p--,ans[i]='P',c++;break;
		case'P':if(s)s--,ans[i]='S',c++;break;
		case'S':if(r)r--,ans[i]='R',c++;break;
	  }
	}
	if(c+c<n){puts("NO");continue;}
	puts("YES");
	for(int i=1;i<=n;i++){
	  if(ans[i]){putchar(ans[i]);continue;}
	  if(p){p--,putchar('P');continue;}
	  if(s){s--,putchar('S');continue;}
	  if(r){r--,putchar('R');continue;}
	}puts("");
	}return 0;
}
#include<cstdio>
const int N=200003;
int n,c[26],d[26],s,t;char a[N],b[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%s%s",&n,a+1,b+1);
	for(int j=0;j<26;j++)c[j]=d[j]=0;
	for(int i=1;i<=n;i++)c[a[i]-'a']++,d[b[i]-'a']++;
	for(int j=0;j<26;j++)
	  if(c[j]!=d[j]){puts("NO");goto Brk;}
	for(int j=0;j<26;j++)
	  if(c[j]>1){puts("YES");goto Brk;}
	s=t=0;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<i;j++)if(a[i]<a[j])s++;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<i;j++)if(b[i]<b[j])t++;
	puts((s^t)&1?"NO":"YES");
	Brk:;
	}return 0;
}
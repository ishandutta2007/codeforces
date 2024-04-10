#include<cstdio>
#include<cstring>
const int N=2e5+3;
char s[N];int n,lst[N],nxt[N],f[N],c,t;
inline void Delete(int i){f[i]=1,lst[nxt[i]]=lst[i],nxt[lst[i]]=nxt[i];}
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=1;i<=n;i++)lst[i]=i-1,nxt[i]=i+1,f[i]=0;
	c=t=0;
	for(int i=1;nxt[i]<=n;)
	  if(i&&s[i]=='A'&&s[nxt[i]]=='B'){
		++c;
		Delete(i),Delete(nxt[i]);
		i=lst[i];
	  }
	  else i=nxt[i];
	for(int i=1;i<=n;i++)t+=!f[i]&&s[i]=='B';
	printf("%d\n",n-c*2-t/2*2);
	}return 0;
}
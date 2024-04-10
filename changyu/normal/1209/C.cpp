#include<cstdio>
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int N=2e5+3;
char s[N],t[N];int n,mx1,mx2,p1,p2;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%s",&n,s);
	for(int l=48;l<58;l++){
	  mx1=mx2=47;p1=-1,p2=n;
	  for(int i=0;i<n;i++){
		if(s[i]<l){
		  if(s[i]<mx1)goto Brk0;
		  t[i]='1';mx1=s[i];
		  p1=max(p1,i);
		}
		if(s[i]>l){
		  if(s[i]<mx2)goto Brk0;
		  t[i]='2';mx2=s[i];
		  p2=min(p2,i);
		}
	  }
	  for(int i=0;i<n;i++)if(s[i]==l){
		if(i>p1)t[i]='1';
		else if(i<p2)t[i]='2';
		else goto Brk0;
	  }
	  for(int i=0;i<n;i++)printf("%c",t[i]);puts("");goto Brk1;
	  Brk0:;
	}puts("-");
	Brk1:;
	}return 0;
}
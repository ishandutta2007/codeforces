//starusc
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
#define re register
const int N=3e5+4;
int a[N];
char s[N];
int main(){
	for(re int T=read(),n,k,fl,c,c0,c1;T--;){
		n=read();k=read();
		memset(a,-1,sizeof(int)*k);
		fl=1;
		scanf("%s",s+1);
		for(re int i=1;i<=n;++i)if(s[i]!='?'){
			c=s[i]^48;
			if(a[i%k]>=0&&a[i%k]!=c){puts("NO");fl=0;break;}
			a[i%k]=c;
		}
		if(fl){
			c0=c1=0;
			for(re int i=0;i<k;i++)if(a[i]>=0){
				if(a[i])c1++;
				else c0++;
			}
			if(max(c0,c1)<=(k>>1))puts("YES");
			else puts("NO");
		}
	}	
	return (0-0);
}
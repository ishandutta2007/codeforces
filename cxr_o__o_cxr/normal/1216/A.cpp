#include<cstdio>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4;
char c[N];
int n,ans=0;
int main(){
	n=read();
	scanf("%s",c+1);
	for(int i=1;i<=n;i+=2){
		if(c[i]-'a'+c[i+1]-'a'!=1){
			ans++;
			if(c[i]=='a')c[i]='b';
			else c[i]='a';
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		putchar(c[i]);
	return (0-0);
}
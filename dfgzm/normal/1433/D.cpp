#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=5005;
int i,j,k,n,m,T,a[maxn],id[maxn];
void out(int x){
	puts("YES");
	for(int i=1;i<=n;i++)
		if(a[i]!=a[x])printf("%d %d\n",i,x);
	for(int i=1;i<=n;i++)
		if(a[i]!=a[x]){
			for(int j=1;j<=n;j++)
				if(a[j]==a[x] && x!=j)printf("%d %d\n",i,j);
			break;
		}
}
int main(){
	T=read();
	while(T--){
		n=read();bool b=true;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=2;i<=n;i++)
			if(a[i]!=a[1]){
				out(i);b=0;
				break;
			}
		if(b)puts("NO");
	}return 0;
}
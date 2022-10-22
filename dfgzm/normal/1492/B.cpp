#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,chs[maxn],a[maxn],cnt;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		int now=0;cnt=0;
		for(i=1;i<=n;i++){
			int x=a[i]=read();
			if(x>now)now=x,chs[++cnt]=i;
		}
		for(i=cnt;i>=1;i--)
			for(j=chs[i];j<=(i==cnt?n:chs[i+1]-1);j++)printf("%d ",a[j]);
		puts("");
	}
	return 0;
}
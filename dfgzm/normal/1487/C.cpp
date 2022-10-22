#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(j+j-i-i==n)putchar('0');
				else if(j+j-i-i<n)putchar('1');
				else printf("-1");
				putchar(' ');
			}
		}puts("");
	}
	return 0;
}
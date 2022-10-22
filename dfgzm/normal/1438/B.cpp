#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,tmp,b;
map<int,int>M;
int main(){
	srand(time(0));
	T=read();
	while(T--){
		b=0;
		M.clear(); 
		n=read();
		for(i=1;i<=n;i++){M[tmp=read()]++;if(M[tmp]>1)b=1;}
		if(b)puts("YES");
		else puts("NO");
	}
	return 0;
}
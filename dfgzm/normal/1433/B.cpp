#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=1000010;
int i,j,k,n,m,T,a[maxn];
int main(){
	T=read();
	while(T--){
		int S=0,ans=1e9,l=1e9,r=-1e9;
		n=read();
		for(i=1;i<=n;i++){
			a[i]=read();
			if(a[i])l=min(l,i),r=max(r,i);
		}
		for(i=l;i<=r;i++)
			if(!a[i])S++;
		cout<<S<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
int a[100002];
bool bo[100002];
int main(){
	int T,n,m,i,j,x,y;
	read(T);
	while(T--){
		read(n);read(m);
		for(i=1;i<=m;++i){
			read(x);
			read(a[i]);
			bo[a[i]]=1;
			read(x);
		}
		for(i=1;i<=n;++i)if(!bo[i])break;
		for(j=1;j<=n;++j){
			if(j!=i)printf("%d %d\n",i,j);
		}
		for(i=1;i<=m;++i)bo[a[i]]=0;
	}
	return 0;
}
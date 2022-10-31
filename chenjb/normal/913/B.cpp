#include<bits/stdc++.h>
#define rep(i,n) for(int i=1;i<=n;++i)
#define N 100005
using namespace std;
int b[N],v[N],f[N],n,m,tot;
int main(){
	scanf("%d",&n);
	rep(i,n-1)scanf("%d",v+i),++b[v[i]];
	rep(i,n)if(!b[i])++f[v[i-1]];
	rep(i,n)if(b[i]&&f[i]<3){puts("No");return 0;}
	puts("Yes");
	//system("pause");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
inline int rd(){
	int f=1,s=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s*f;
}
const int N= 1e5+50;
int t,n,vis[N],q,a[N]; 
int main(){
	t=rd(); 
	while(t--){
		n=rd(); q=rd();
		for(int i=1;i<=n;++i)a[i]=rd(),vis[i]=0;
		int i=n,x=0;
		while(i>=1&&x<q){
			if(a[i]>x)++x;
			vis[i]=1;--i;
		}
		while(i>=1){
			if(a[i]<=q)vis[i]=1;
			--i;
		}
		for(int i=1;i<=n;++i)printf("%d",vis[i]);
		printf("\n");
	}
	
	return 0;
}
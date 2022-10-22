#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0,c='0';do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=100010;
int i,j,k,n,m,T,vis[maxn];
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	cin>>T;
	while(T--){
		n=read();m=read();
		for(i=1;i<=m;i++){
			int x=read(),y=read(),z=read();
			vis[y]=1;
		}
		for(i=1;i<=n;i++){
			if(!vis[i]){
				for(j=1;j<=n;j++)
					if(i!=j)printf("%d %d\n",i,j);
				break;
			}
		}
		for(i=1;i<=n;i++)vis[i]=0;
	}
}
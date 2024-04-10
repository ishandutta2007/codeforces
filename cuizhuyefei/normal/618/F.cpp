#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int N = 1666666;
int n;pair<int,int>pos[N];bool vis[N];
ll a[N],b[N];bool flag;
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%lld",&a[i]),a[i]+=a[i-1];
	rep(i,1,n)scanf("%lld",&b[i]),b[i]+=b[i-1];
	if(a[n]>=b[n]){rep(i,1,n)swap(a[i],b[i]);flag=1;}
	
		pair<int,int> x,y;
		for(int i=0,j=0;i<=n;i++){
			while(j+1<=n&&b[j+1]-a[i]<n)j++;//printf("<%d,%d>\n",i,j);
			if(!vis[b[j]-a[i]])pos[b[j]-a[i]]=pair<int,int>(i,j),vis[b[j]-a[i]]=1;
			else x=pos[b[j]-a[i]],y=pair<int,int>(i,j);
		}
		if(!flag){
			printf("%d\n",y.fi-x.fi);rep(i,x.fi+1,y.fi)printf("%d ",i);puts("");
			printf("%d\n",y.se-x.se);rep(i,x.se+1,y.se)printf("%d ",i);puts("");
		}
		else{
			printf("%d\n",y.se-x.se);rep(i,x.se+1,y.se)printf("%d ",i);puts("");
			printf("%d\n",y.fi-x.fi);rep(i,x.fi+1,y.fi)printf("%d ",i);puts("");
		}
	
	return 0;
}
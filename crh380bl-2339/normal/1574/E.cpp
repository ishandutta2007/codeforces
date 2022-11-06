#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define inv2 499122177
#define N 1000002
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
int a[N][2],b[N][2],s1=0,s2=0;
int n1=0,n2=0,t1=0,t2=0;
struct node{
	int x,y;
	bool operator <(const node&z)const{
		return x==z.x?y<z.y:x<z.x;
	}
};
map<node,int>M;
int ksm(int x,int y){
	assert(y>=0);
	int t=1;
	while(y){
		if(y&1)t=1LL*t*x%mod;
		x=1LL*x*x%mod;
		y>>=1;
	}
	return t;
}
void cle(int x,int y){
	node p=(node){x,y};
	if(!M[p])return;
	if(M[p]==-1){
		--b[y][x&1];
		if(b[y][0]+b[y][1]==0)--s2;
		if(b[y][1^(x&1)]&&!b[y][x&1])--n2;
		
		--a[x][y&1];
		if(a[x][0]+a[x][1]==0)--s1;
		if(a[x][1^(y&1)]&&!a[x][y&1])--n1;
		
		if((x+y)&1)--t1;
		else --t2;
	}
	else{
		--b[y][1^(x&1)];
		if(b[y][0]+b[y][1]==0)--s2;
		if(!b[y][1^(x&1)]&&b[y][x&1])--n2;

		--a[x][1^(y&1)];
		if(a[x][0]+a[x][1]==0)--s1;
		if(!a[x][1^(y&1)]&&a[x][y&1])--n1;
		
		if((x+y)&1)--t2;
		else --t1;
	}
	M[p]=0;
}
void add(int x,int y,int o){
	node p=(node){x,y};
	M[p]=o;
	if(o==-1){
		++b[y][x&1];
		if(b[y][0]+b[y][1]==1)++s2;
		if(b[y][1^(x&1)]&&b[y][x&1]==1)++n2;
		
		++a[x][y&1];
		if(a[x][0]+a[x][1]==1)++s1;
		if(a[x][1^(y&1)]&&a[x][y&1]==1)++n1;
		
		if((x+y)&1)++t1;
		else ++t2;
	}
	else{
		++b[y][1^(x&1)];
		if(b[y][0]+b[y][1]==1)++s2;
		if(b[y][1^(x&1)]==1&&b[y][x&1])++n2;
		
		++a[x][1^(y&1)];
		if(a[x][0]+a[x][1]==1)++s1;
		if(a[x][1^(y&1)]==1&&a[x][y&1])++n1;
		
		if((x+y)&1)++t2;
		else ++t1;	
	}
}
int main(){
	int n,m,k,x,y,o,ans;
	scanf("%d%d%d",&n,&m,&k);
	while(k--){
		scanf("%d%d%d",&x,&y,&o);
		cle(x,y);
		if(o!=-1)add(x,y,o*2-1);
		ans=0;
		if(!n1)ans=(ans+ksm(2,n-s1))%mod;
		if(!n2)ans=(ans+ksm(2,m-s2))%mod;
		if(!t1)--ans;
		if(!t2)--ans;
		ans=(ans+mod)%mod;
		printf("%d\n",ans);
	}
	return 0;
}
#include<bits/stdc++.h>
#define int long long
const int N=1000500;
using namespace std;

int n,x,y,X,Y,sz[N];
int fib[N],cnt;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,tg;
}e[N];int hd[N],S=1;
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr],0},hd[fr]=S;
}

void fnd(int k,int f,int p,int pr){
	sz[k]=1;
	fore(k)if(_to!=f&&!e[i].tg)	
		fnd(_to,k,p,i),sz[k]+=sz[_to];
	if(sz[k]==fib[p]&&(!X&&!Y)){
		e[pr].tg=e[pr^1].tg=1;
		X=k,Y=f;
		return ;
	}
	if(sz[k]==fib[p+1]&&(!X&&!Y)){
		e[pr].tg=e[pr^1].tg=1;
		X=f,Y=k;
		return ;
	}
}

int solve(int k,int p){
	if(p<=1)return 1;
	X=Y=0;	
	fnd(k,0,p-2,0);
	if(!X||!Y)return 0;
	int a=X,b=Y;
	return solve(a,p-2)&&solve(b,p-1);
}

main(){
	ios::sync_with_stdio(false);
	cin>>n;
	fib[0]=fib[1]=1;
	for(cnt=2;fib[cnt-1]<n;cnt++)fib[cnt]=fib[cnt-1]+fib[cnt-2];--cnt;
	if(fib[cnt]!=n)puts("NO"),exit(0);
	for(int i=1;i<n;i++)cin>>x>>y,add(x,y),add(y,x);
	puts(solve(1,cnt)?"YES":"NO");
}
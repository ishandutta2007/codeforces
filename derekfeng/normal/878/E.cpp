#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7,I=(M+1)/2,N=1e5+4;
const ll inf=1e10;
int n,q,rt,a[N],pw[N],pi[N];
int pre[N],nx[N][17],cw[N][17],ky[N];
int ch[N][2];ll vl[N],mu[N],ad[N];
mt19937 gwj(114514);
int qry(int l,int r){
	return (ll)(pre[r]-pre[l-1]+M)*pi[l]%M;
}
void push(int i,ll a,ll b){
	vl[i]=vl[i]*a,mu[i]=mu[i]*a;
	ad[i]=ad[i]*a,vl[i]+=b,ad[i]+=b;
}
void pushdown(int i){
	if(ch[i][0])push(ch[i][0],mu[i],ad[i]);
	if(ch[i][1])push(ch[i][1],mu[i],ad[i]);
	mu[i]=1,ad[i]=0;
}
int merge(int x,int y){
	if(!x||!y)return x|y;
	if(ky[x]<ky[y]){
		pushdown(x);
		ch[x][1]=merge(ch[x][1],y);
		return x;
	}pushdown(y);
	ch[y][0]=merge(x,ch[y][0]);
	return y;
}
void split(int i,ll k,int &x,int &y){
	if(!i){x=y=0;return;}
	pushdown(i);
	if(vl[i]<=k)x=i,split(ch[i][1],k,ch[i][1],y);
	else y=i,split(ch[i][0],k,x,ch[i][0]);
}
void iter(int i,int x){
	if(!i)return;
	nx[i][0]=x,cw[i][0]=qry(x+1,i);
	iter(ch[i][0],x),iter(ch[i][1],x);
}
int main(){
	scanf("%d%d",&n,&q);pw[0]=pi[0]=1;
	for(int i=1;i<=n;i++)
		pw[i]=pw[i-1]*2%M,pi[i]=(ll)pi[i-1]*I%M;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i]=((ll)pw[i]*a[i]%M+M+pre[i-1])%M;
		vl[i]=a[i],mu[i]=1,ky[i]=gwj();
	}
	for(int i=n;i;i--){
		if(rt)push(rt,2,a[i]);
		int A,B;split(rt,a[i],A,B);
		rt=merge(A,merge(i,B));
		split(rt,0,A,rt),split(rt,inf,rt,B);
		iter(A,i-1),iter(B,0);
	}iter(rt,0);
	for(int i=1;i<=n;i++)for(int t=1;t<17;t++)if(nx[i][t-1]){
		int w=nx[i][t-1];
		nx[i][t]=nx[w][t-1],cw[i][t]=(cw[i][t-1]+cw[w][t-1])%M;
	}while(q--){
		int l,r;scanf("%d%d",&l,&r);int sum=0;
		for(int t=16;~t;t--){
			int p=nx[r][t],w=cw[r][t];
			if(p>l)(sum+=w)%=M,r=p;
		}(sum+=sum)%=M,(sum+=qry(l,r))%=M,printf("%d\n",sum);
	}
}
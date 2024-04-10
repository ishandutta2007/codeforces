#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+3,L=2e6+3;
int n,l,t[N],ansx[L],ansy[L];
ll z[N],x[N],y[N];
inline ll Ceil (ll a,ll b){return a<=0?a/b:(a+b-1)/b;}
inline ll Floor(ll a,ll b){return a>=0?a/b:(a-b+1)/b;}
inline bool Solve(ll*x,int*ansx){
	ll L=-l,R= l,dq,dr,dx;
	for(ll id=0;id<n;id++){
		dq=z[t[id+1]]/l-z[t[id]]/l,dr=z[t[id+1]]%l-z[t[id]]%l,dx=x[t[id+1]]-x[t[id]];
		if(!dq&&std::abs(dx)>dr)L=l,R=-l;
		if(dq>0)
			L=std::max(L,Ceil(+dx-dr,+dq)),R=std::min(R,Floor(+dx+dr,+dq));
		if(dq<0)
			L=std::max(L,Ceil(-dx-dr,-dq)),R=std::min(R,Floor(-dx+dr,-dq));
	}
	dq=z[t[n]]/l+1,dr=z[t[n]]%l,dx=x[t[n]];
	L=std::max(L,Ceil(+dx+dr-l,dq)),R=std::min(R,Floor(+dx-dr+l,dq));
	if(L>R)return 0;
	for(int d=L;d<=L+1&&d<=R;d++){
		int c=0;
		x[n+1]=d;
		for(int id=0;id<=n;id++){
			dq=(id==n?0:z[t[id+1]]/l)-z[t[id]]/l,dr=(id==n?l:z[t[id+1]]%l)-z[t[id]]%l,dx=x[t[id+1]]-x[t[id]];
			if(dr+dx-d*dq&1)goto Brk;
			for(int j=0;j*2<dr+dx-d*dq;j++)ansx[++c]= 1;
			for(int j=0;j*2<dr-dx+d*dq;j++)ansx[++c]=-1;
		}
		return 1;
	  Brk:;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",z+i,x+i,y+i),t[i]=i;
		ll tmp=x[i]+y[i];x[i]-=y[i];y[i]=tmp;
	}
	std::sort(t+1,t+1+n,[](const int&i,const int&j){return z[i]%l<z[j]%l;});
	z[n+1]=l,t[n+1]=n+1;
	if(!Solve(x,ansx)||!Solve(y,ansy))return 0*puts("NO");
	for(int i=1;i<=l;i++){
		if(ansx[i]>0&&ansy[i]>0)putchar('R');
		if(ansx[i]<0&&ansy[i]>0)putchar('U');
		if(ansx[i]<0&&ansy[i]<0)putchar('L');
		if(ansx[i]>0&&ansy[i]<0)putchar('D');
	}
	putchar('\n');
	return 0;
}
#include<bits/stdc++.h>
#define int long long
const int N=11;
using namespace std;

int n,t;
double nt;

struct node{
	double x,v,m;
	void input(){cin>>x>>v>>m;}
	void run(double t){x+=t*v;}
}e[N];

double calc(node a,node b){
	if(a.x>b.x)swap(a,b);
	if(abs(a.x-b.x)<1e-5)return 1e18;
	if(a.v-b.v<=0)return 1e18;
	return (b.x-a.x)/(a.v-b.v);
}

void pz(node&a,node&b){
	node c=a,d=b;
	c.v=((a.m-b.m)*a.v+2*b.m*b.v)/(a.m+b.m); 
	d.v=((b.m-a.m)*b.v+2*a.m*a.v)/(a.m+b.m);
	a=c,b=d;
}

void solve(){
	cin>>n>>t;
	for(int i=1;i<=n;i++)e[i].input();
	while(nt<t){
		double mn=t-nt;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++){
				double nw=calc(e[i],e[j]);
				if(nw<mn)mn=nw;
			}
		for(int i=1;i<=n;i++)
 			e[i].run(mn);
 		for(int i=1;i<=n;i++)
 			for(int j=i+1;j<=n;j++)
 				if(abs(e[i].x-e[j].x)<1e-5)
 					pz(e[i],e[j]);
		nt+=mn;
	}
	for(int i=1;i<=n;i++)
		printf("%.9lf\n",e[i].x);
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}
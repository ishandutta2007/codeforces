#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int m,n;long long c[1111111],t[1111111];
void add(int p,long long v){for(;p<=n;p+=p&-p)t[p]+=v;}
void add(int l,int r,long long v){add(l,v); add(r+1,-v);}
long long ask(int p,long long a=0){for(;p;p-=p&-p)a+=t[p]; return a;}
struct p{
	int l,r,c;
	friend bool operator<(p x,p y){return x.r<y.r;}
};
set<p>s;
char _[233];
int main(){
	cin>>n>>m;
	s.insert((p){1,n,1});
	for(int i=1;i<=m;++i){
		int x;
		scanf("%s",_);
		if(_[0]=='A'){
			int C,v; scanf("%d%d",&C,&v); c[C]+=v;
		}else if(_[0]=='Q')scanf("%d",&x),printf("%lld\n",c[s.lower_bound((p){0,x,0})->c]+ask(x));
		else{
			int l,r,C;
			scanf("%d%d%d",&l,&r,&C); int L=l,R=r;
			while(r>=l){
				p z=*s.lower_bound((p){0,r,0});
				s.erase(z); add(z.l,z.r,c[z.c]); //cerr<<"- "<<z.l<<' '<<z.r<<endl;
				if(z.r>r) s.insert((p){r+1,z.r,z.c}),add(r+1,z.r,-c[z.c]),z.r=r;
				if(z.l<l) s.insert((p){z.l,l-1,z.c}),add(z.l,l-1,-c[z.c]),z.l=l;
				r=z.l-1;
			}
			s.insert((p){L,R,C}),add(L,R,-c[C]);// cerr<<"+ "<<L<<' '<<R<<endl;
		}//err<<ask(233333)<<endl;
	}
}
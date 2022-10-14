#include <bits/stdc++.h>
#define iter(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,a) iter(i,0,(a))
#define rep1(i,a) iter(i,1,(a)+1)
using namespace std;
const int MXN=100005,B=200;
const int BCT=MXN/B+5;
long long fa[MXN],ou[MXN],lz[BCT];
int tg[BCT],n,q,op,l,r,x,u,v,c,la=0;
inline int refa(int u){return max(0ll,fa[u]-lz[u/B]);}
inline int reou(int u){return max(0ll,(tg[u/B]>B)?fa[u]-lz[u/B]:ou[u]);}
int main() {
	cin>>n>>q;c=n/B+1;
	fa[0]=ou[0]=-100000;
	rep1(i,n-1){
		cin>>fa[i];fa[i]--;
		if(fa[i]/B!=i/B)ou[i]=fa[i];
		else ou[i]=ou[fa[i]];
	}
	while(q--){cin>>op;
		if(op==1){
			cin>>l>>r>>x;
			//l^=la;r^=la;x^=la;
			l--;
			rep(i,c){
				int L=i*B;
				int R=min(L+B,n),bid=L/B;
				if(r<=L||R<=l)continue;
				if(l<=L&&R<=r){
					tg[bid]++;
					if(tg[bid]>B){lz[bid]+=x;continue;}
				}
				iter(j,L,R) {
					fa[j]-=lz[bid];
					if(l<=j&&j<r)fa[j]-=x;
					if(fa[j]<L)ou[j]=fa[j];
					else ou[j]=ou[fa[j]];
				}
				lz[bid]=0;
			}
		}else{
			cin>>u>>v;
			//u^=la;v^=la;
			u--;v--;
			while(reou(u)!=reou(v))(u<v)?(v=reou(v)):(u=reou(u));
			while(refa(u)!=refa(v))(u<v)?(v=refa(v)):(u=refa(u));
			if(u!=v)u=refa(u);
			cout<<(la=u+1)<<'\n';
		}
		//rep(i,n)cout<<reou(i)<<" \n"[i==n-1];
		//rep(i,n)cout<<refa(i)<<" \n"[i==n-1];
	}
}
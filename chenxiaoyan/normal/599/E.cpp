#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define X first
#define Y second
int f[13][1<<13],n;
bitset<1<<13> vis[13];
vector<pair<int,int> > eg;
vector<pair<pair<int,int>,int> > lca;
inline int lowbit(int x){return x&-x;}
inline void bin(int x){for(int i=0;i<n;i++)cout<<!!(x&1<<i);}
int dp(int rt,int stt){
	if(stt==(1<<rt))return 1;
	int &res=f[rt][stt];
	if(vis[rt][stt])return res;
	vis[rt].set(stt);
	int ost=stt;stt^=1<<rt;int hav=lowbit(stt);
	for(int i=stt;i;i=(i-1)&stt)if(i&hav){
//		cout<<rt<<" ";bin(stt^1<<rt);cout<<":";bin(i);
		int j;
		bool ok=true;
		for(j=0;j<lca.size();j++)if(ost&1<<lca[j].X.X&&ost&1<<lca[j].X.Y&&ost&1<<lca[j].Y){
			int two=!!(i&1<<lca[j].X.X)+!!(i&1<<lca[j].X.Y);bool one=i&1<<lca[j].Y;
			if(two==2&&!one){ok=false;break;}
			if(two==1&&lca[j].Y!=rt){ok=false;break;}
			if(!two)
				if(lca[j].X.X==rt||lca[j].X.Y==rt)if(lca[j].Y!=rt){ok=false;break;}else;
				else if(one){ok=false;break;}
		}
//		if(!ok)puts("(!OK)");
		if(!ok)continue;
		int con_to_rt=0,will_be_j;
		for(j=0;j<eg.size();j++)if(ost&1<<eg[j].X&&ost&1<<eg[j].Y){
			bool fst=i&1<<eg[j].X,scd=i&1<<eg[j].Y;
			if(fst==scd)continue;
			if(eg[j].X==rt||eg[j].Y==rt)
				if(!con_to_rt)con_to_rt=1,will_be_j=eg[j].X==rt?eg[j].Y:eg[j].X;
				else{con_to_rt=2;break;}
			else{con_to_rt=2;break;}
		}
//		puts(con_to_rt==2?"(con_to_rt>1)":"");
		if(!con_to_rt)for(j=0;j<n;j++)if(i&1<<j)res+=dp(j,i)*dp(rt,ost^i);else;
		else if(con_to_rt==1)res+=dp(will_be_j,i)*dp(rt,ost^i);
	}
	return res;
}
signed main(){
	int m,q,i;scanf("%lld%lld%lld",&n,&m,&q);
	while(m--){
		int x,y;scanf("%lld%lld",&x,&y);x--;y--;if(x>y)swap(x,y);
		if(find(eg.begin(),eg.end(),mp(x,y))==eg.end())eg.push_back(mp(x,y));
	}
	while(q--){
		int x,y,z;scanf("%lld%lld%lld",&x,&y,&z);x--;y--;z--;if(x>y)swap(x,y);
		if(x==y)if(z==x)continue;else return !printf("0");
		bool ok=true;
		for(i=0;i<lca.size();i++)
			if(lca[i].X.X==x&&lca[i].X.Y==y)
				if(lca[i].Y==z){ok=false;break;}
				else return !printf("0");
		if(ok)lca.push_back(mp(mp(x,y),z));
	}
//	cout<<"\n";
//	int cl=clock();
	printf("%lld",dp(0,(1<<n)-1));
//	for(i=0;i<(1<<n);i++){
//		puts("");for(int j=0;j<n;j++)cout<<"f["<<j<<"][",bin(i),cout<<"]="<<f[j][i]<<"\t";
//	}
//	cout<<"\n"<<clock()-cl<<"ms";
	return 0;
}
/*1
4 0 0
*/
/*2
4 0 1
3 4 2
*/
/*3
3 1 0
1 2
*/
/*4
3 0 2
2 3 2
2 3 1
*/
/*5
4 1 2
1 2
2 2 2
3 4 2
*/
/*6
6 3 2
1 2
2 3
3 4
1 2 1
2 3 2
*/
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
const int N = 233333;
int q,tp[N],x[N],y[N],cnt,tot;
map<ll,int>Hash;map<Pii,int>Ans;
vector<Pii>dot[N];
inline int gcd(int a, int b){return !b?a:gcd(b,a%b);}
inline Pii getdot(int x1, int y1, int x2, int y2){
	int x=x1+x2,y=y1+y2,g=gcd(x,y);return Pii(x/g,y/g);
}
int main(){
	scanf("%d",&q);
	rep(i,1,q)scanf("%d%d%d",&tp[i],&x[i],&y[i]);
	rep(t,1,q)
		if(tp[t]==1){
			int num;ll tmp=1LL*x[t]*x[t]+1LL*y[t]*y[t];
			if(!Hash.count(tmp))num=Hash[tmp]=++cnt;else num=Hash[tmp];
			per(i,SZ(dot[num])-1,0)Ans[getdot(x[t],y[t],dot[num][i].first,dot[num][i].second)]+=2;
			dot[num].push_back(Pii(x[t],y[t]));int g=gcd(x[t],y[t]);Ans[Pii(x[t]/g,y[t]/g)]++;tot++;
		}
		else if(tp[t]==2){
			int num=Hash[1LL*x[t]*x[t]+1LL*y[t]*y[t]];int p=0;
			per(i,SZ(dot[num])-1,0)if(dot[num][i].first==x[t]&&dot[num][i].second==y[t]){p=i;break;}
			per(i,SZ(dot[num])-1,0)if(i!=p)Ans[getdot(x[t],y[t],dot[num][i].first,dot[num][i].second)]-=2;
			dot[num].erase(dot[num].begin()+p);int g=gcd(x[t],y[t]);Ans[Pii(x[t]/g,y[t]/g)]--;tot--;
		}
		else{int g=gcd(x[t],y[t]);printf("%d\n",tot-Ans[Pii(x[t]/g,y[t]/g)]);}
	return 0;
}
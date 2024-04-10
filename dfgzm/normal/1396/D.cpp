#include <bits/stdc++.h>
#define M(x) (x=x>=mod?x-mod:x)
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
const int maxn=2010,mod=1e9+7;
int i,j,k,n,m,L;
int X[maxn],Y[maxn],c[maxn][maxn],cnt0,cnt1,s0=1,s1=1;
struct edge{
	int x,y,c;
}E[maxn];int cnt;
vector<pii>C[maxn],C2[maxn];
void init(){
	sort(X+1,X+1+cnt0);
	sort(Y+1,Y+1+cnt1);
	for(int i=2;i<=cnt0;i++)
		if(X[i]!=X[i-1])X[++s0]=X[i];
	for(int i=2;i<=cnt1;i++)
		if(Y[i]!=Y[i-1])Y[++s1]=Y[i];
	for(int i=1;i<=cnt;i++){
		int x0=lower_bound(X+1,X+1+s0,E[i].x)-X,y0=lower_bound(Y+1,Y+1+s1,E[i].y)-Y;
		//cout<<"x0="<<x0<<" y0="<<y0<<' '<<X[x0]<<' '<<Y[y0]<<endl;
		c[x0][y0]=E[i].c;
		C[y0].push_back((pii){x0,E[i].c});
		C2[x0].push_back((pii){y0,E[i].c});
	}
}
int ans[maxn],last[maxn],nxt[maxn],S[maxn];
multiset<int>Mp[maxn];
multiset<int>::iterator it;
int is[maxn];
ll Ans;

namespace Segment_tree{
	int tree[maxn*4],Min[maxn*4],lazy[maxn*4];ll w[maxn*4];
	void update(int root){
		Min[root]=min(Min[root*2],Min[root*2+1]);
		tree[root]=(tree[root*2]+tree[root*2+1])%mod;
	}
	void pushdown(int root,int L,int R){
		if(!lazy[root])return;
		lazy[root*2]=lazy[root];Min[root*2]=lazy[root];tree[root*2]=w[root*2]*lazy[root]%mod;
		lazy[root*2+1]=lazy[root];Min[root*2+1]=lazy[root];tree[root*2+1]=w[root*2+1]*lazy[root]%mod;
		lazy[root]=0;
	}
	void build(int root,int L,int R,int *ans,int *y){
		if(L==R){
			Min[root]=ans[L];
			tree[root]=1ll*ans[L]*(y[L]-y[L-1])%mod;
			w[root]=y[L]-y[L-1];
			lazy[root]=0;
			//cout<<"root="<<root<<' '<<L<<' '<<y[L]<<' '<<y[L-1]<<' '<<ans[L]<<endl;
		}else{
			build(root*2,L,Mid,ans,y);
			build(root*2+1,Mid+1,R,ans,y);
			update(root);w[root]=(w[root*2]+w[root*2+1])%mod;
			lazy[root]=0;
			//cout<<"building.. root="<<root<<" L="<<L<<" R="<<R<<' '<<w[root]<<' '<<tree[root]<<' '<<Min[root]<<endl;
		}
	}
	int find(int root,int L,int R,int s){
		if(L==R){
			if(Min[root]<=s)return L;
			else return L-1;
		}else{
			pushdown(root,L,R);
			if(Min[root*2+1]<=s)return find(root*2+1,Mid+1,R,s);
			else return find(root*2,L,Mid,s);
		}
	}
	void add(int root,int L,int R,int l,int r,int s){
		if(L==l && R==r){
			lazy[root]=s;
			Min[root]=s;
			tree[root]=1ll*s*w[root]%mod;
		}else{
			pushdown(root,L,R);
			if(r<=Mid)add(root*2,L,Mid,l,r,s);
			else if(l>Mid)add(root*2+1,Mid+1,R,l,r,s);
			else add(root*2,L,Mid,l,Mid,s),add(root*2+1,Mid+1,R,Mid+1,r,s);
			update(root);
		}
	}
	ll updateans(int L,int s1){
		ll sum=L*w[1]%mod-tree[1]+w[1];
		//cout<<"updateans "<<L<<' '<<w[1]<<' '<<tree[1]<<' '<<sum<<endl;
		return (sum+1000000007)%(1000000007);
	}
}using namespace Segment_tree;

int main() {
	cin>>n>>m>>L;
	//X[++cnt0]=L;
	X[++cnt0]=L+1;
	Y[++cnt1]=L+1;
	for(i=1;i<=n;i++){
		int x=read()+1,y=read()+1,C=read();
		E[++cnt]={x,y,C};
		X[++cnt0]=x;
		Y[++cnt1]=y;
	}init();
	for(int x=1;x<s0;x++){
//		cout<<"x="<<x<<' '<<X[x]<<endl;
		int all=0,p=0;
		
		memset(last,-1,sizeof(last));
		for(int co=1;co<=m;co++)Mp[co].clear();
		for(int l=1;l<=s1;l++)nxt[l]=s1+1;
		memset(ans,-1,sizeof(ans));
		for(int l=1;l<=s1;l++){
//			cout<<"l="<<l<<endl;
			while(all!=m && p<s1){
				++p;
//				cout<<"p="<<p<<endl;
				for(int k=0;k<C[p].size();k++){
					int xs=C[p][k].first,c=C[p][k].second;
					if(xs<=x){
//						cout<<"insert "<<xs<<' '<<c<<endl;
						Mp[c].insert(p);
						is[c]++;
						all+=(is[c]==1);
					}
				}if(all==m)break;
			}
			if(all==m)ans[l]=Y[p];
			else ans[l]=Y[s1];
//			cout<<"ans["<<l<<"]="<<ans[l]<<' '<<p<<' '<<Y[0]<<' '<<Y[1]<<' '<<Y[2]<<' '<<Y[3]<<' '<<s1<<endl;
			for(int k=0;k<C[l].size();k++){
				int xs=C[l][k].first,c=C[l][k].second;
				if(xs<=x){
//					cout<<"delate "<<xs<<' '<<c<<endl;
					is[c]--;
					all-=(is[c]==0);
				}
			}
		}//ans
		build(1,1,s1,ans,Y);Ans+=updateans(L,s0)*(X[x+1]-X[x])%mod*(X[1]-X[0])%mod;M(Ans);
//		cout<<"Ans="<<Ans<<' '<<X[0]<<' '<<X[1]<<' '<<X[x]<<' '<<X[x+1]<<endl;

		for(int h=2;h<=x;h++){
			//cout<<"h="<<h<<endl;
			for(int k=0;k<C2[h-1].size();k++){
				int y=C2[h-1][k].first,c=C2[h-1][k].second;
//				cout<<"erase "<<y<<' '<<c<<endl;
				Mp[c].erase(Mp[c].find(y));
				int L,R;it=Mp[c].upper_bound(y);
				if(it==Mp[c].end())R=Y[s1];else R=Y[*it];
				if(it==Mp[c].begin())L=1;
				else{--it;L=*it;L++;}
//				cout<<"L="<<L<<' '<<"R="<<R<<endl;
				int rig=find(1,1,s1,R);
//				cout<<"RIGHT="<<rig<<endl;
				if(L<=rig)add(1,1,s1,L,rig,R);
			}Ans+=updateans(L,s0)*(X[x+1]-X[x])%mod*(X[h]-X[h-1])%mod;M(Ans);
//			cout<<"ANS="<<Ans<<' '<<x<<' '<<X[h]<<' '<<X[h-1]<<' '<<X[x+1]<<' '<<X[x]<<endl;
		}
		
//		cout<<"Ans="<<Ans<<endl<<endl<<endl<<endl<<endl;
	}cout<<Ans<<endl;
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
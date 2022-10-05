#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=200005,S=125;
int a[N],id[N],val[S][6],mul[S][S],las[S];
int r[6],vis[6],in[S],p[S],q[S],now[S],bas[S];
int n,K,cnt,tot,fac;
ll ans;

void dfs(int k,int owo){
	if(k==K+1){
		id[owo]=++cnt;
		rep(i,1,K)val[cnt][i]=r[i];
		return;
	}
	rep(i,1,K)
		if(!vis[i]){
			r[k]=i;
			vis[i]=1;
			dfs(k+1,owo*10+i);
			vis[i]=0;
		}
}
int Mul(int a[6],int b[6]){
	int res=0;
	rep(i,1,K)
		res=res*10+b[a[i]];
	return id[res];
}

void upd(int k){
	if(!las[a[k]]){
		las[a[k]]=p[++tot]=k;
		per(i,tot,2)swap(p[i],p[i-1]);
	}
	else{
		int cur=0;
		rep(i,1,tot)
			if(p[i]==las[a[k]]){
				cur=i;
				break;
			}
		las[a[k]]=p[cur]=k;
		per(i,cur,2)swap(p[i],p[i-1]);
	}
}

int main(){
	read(n),read(K);
	dfs(1,0);
	rep(i,1,cnt)rep(j,1,cnt)
		mul[i][j]=Mul(val[i],val[j]);
	rep(i,1,n){
		int sum=0;
		rep(j,1,K){
			read(r[j]);
			sum=sum*10+r[j];
		}
		a[i]=id[sum];
	}
	per(i,n,1){
		memset(in,0,sizeof in);
		upd(i),in[1]=1;
		int G=1,B=0;
		p[tot+1]=n+1;
		now[G]=1;
		rep(k,1,tot){
			if(!in[a[p[k]]]){
				int w=a[p[k]],l=0,r=0;
				q[r++]=w,in[w]=1;
				now[++G]=w;
				bas[++B]=w;
				while(l<r){
					int u=q[l++],o;
					rep(t,1,B){
						int w=bas[t];
						if(!in[mul[u][w]]){
							q[r++]=mul[u][w];
							in[mul[u][w]]=1;
							now[++G]=mul[u][w];
						}
					}
				}
			}
			ans+=(p[k+1]-p[k])*G;
		}
	}
	cout<<ans<<endl;
	return 0;
}
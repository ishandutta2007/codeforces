#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int K=320;
const int M=20;
int n,k;
int pri[N],tot;
ll phi[N];
bool np[N];
inline void euler(){
	int i,j;
	phi[1]=1;
	for(i=2;i<N;i++){
		if(!np[i]){
			pri[++tot]=i;
			phi[i]=i-1;
		}
		for(j=1;j<=tot;j++){
			if(i*pri[j]>=N) break;
			np[i*pri[j]]=1;
			if(i%pri[j]) phi[i*pri[j]]=phi[i]*(pri[j]-1);
			else{
				phi[i*pri[j]]=phi[i]*pri[j];
				break;
			}
		}
	}
}
ll s1[N][K],s2[N][K];
ll dp[M][N];
inline ll calc(int l,int r){
	ll ans=0;l--;
	if(r<K) ans+=s1[r][r];
	else ans+=s1[r][K-1]+s2[r][1];
	if(l<K) ans-=s1[r][l];
	else ans-=s1[r][K-1]+s2[r][r/l+1]+phi[r/l]*ll(l-max(K-1,r/(r/l+1)));
	return ans;
}
struct node{
	int l,r,id;
	inline node(int l=0,int r=0,int id=0):l(l),r(r),id(id){}
}q[N<<1];
int hd,tl;
inline ll cost(int id,int x,int y){
	return dp[id][x]+calc(x+1,y);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	euler();
	for(i=1;i<N;i++) phi[i]+=phi[i-1];
	for(i=1;i<N;i++){
		for(j=1;j<K;j++) s1[i][j]=s1[i][j-1]+phi[i/j];
		int l=K,r;
		while(l<=i){
			int t=i/l;r=i/t;
			s2[i][t]=s2[i][t+1]+ll(r-l+1)*phi[t];
			l=r+1;
		}
	}
	for(i=1;i<N;i++) dp[1][i]=calc(1,i);
	for(j=1;j<M;j++){
		hd=tl=1;q[hd]=node(j+1,N-1,j);
		for(i=j+1;i<N;i++){
			node t=q[hd];
			dp[j+1][i]=cost(j,t.id,i);
			if(i==t.r) hd++;
			else q[hd].l++;
			while(hd<=tl){
				t=q[tl];
				if(cost(j,i,t.l)<cost(j,t.id,t.l)) tl--;
				else if(cost(j,i,t.r)>=cost(j,t.id,t.r)){
					if(t.r<N-1) q[++tl]=node(t.r+1,N-1,i);
					break;
				}
				else{
					int l=t.l,r=t.r;
					while(l<r){
						int mid=l+r>>1;
						if(cost(j,i,mid)>=cost(j,t.id,mid)) l=mid+1;
						else r=mid;
					}
					q[tl].r=l-1;
					q[++tl]=node(l,N-1,i);
					break;
				}
			}
			if(hd>tl) q[++tl]=node(i+1,N-1,i);
		}
	}
	int t;cin>>t;
	while(t--){
		cin>>n>>k;
		if(k>=M) cout<<n<<endl;
		else cout<<dp[k][n]<<endl;
	}
	return 0;
}
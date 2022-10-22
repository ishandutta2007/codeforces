#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5005;
int n,m;
ll a[20][N],s[20];
map<ll,pair<int,int> > mp;
pair<int,int> pre[20][N];
int vis[20],len[20];
struct node{
	int id,to;
	ll val;
	bool operator <(const node &b)const
	{
		return id<b.id;
	}
	node(int id,int to,ll val):id(id),to(to),val(val){}
};
int dp[1<<15];
vector<node> f[1<<15],ans;
int pos[20];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>len[i];
		for(j=1;j<=len[i];j++){
			cin>>a[i][j];
			s[i]+=a[i][j];
			mp[a[i][j]]=make_pair(i,j);
		}
	}
	ll avr=0;
	for(i=1;i<=n;i++) avr+=s[i];
	if(avr%n){
		cout<<"No";
		return 0;
	}
	avr/=n;
	for(i=1;i<=n;i++){
		for(j=1;j<=len[i];j++){
			ll v=avr-(s[i]-a[i][j]);
			if(mp.find(v)==mp.end()) continue;
			pre[i][j]=mp[v];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=len[i];j++){
			memset(vis,0,sizeof(vis));
			vis[i]=j;
			int px=i,py=j;
			bool flag=1;
			while(1){
				int tx=pre[px][py].first,ty=pre[px][py].second;
				if(tx==i&&ty==j) break;
				if(!tx||vis[tx]){
					flag=0;
					break;
				}
				vis[tx]=ty;
				px=tx;py=ty;
			}
			if(!flag) continue;
			int stat=0;
			for(k=1;k<=n;k++)
				if(vis[k]) stat|=(1<<k-1);
			if(f[stat].size()) continue;
			for(k=1;k<=n;k++){
				if(vis[k])
					f[stat].push_back(node(k,pre[k][vis[k]].first,a[k][vis[k]]));
			}
		}
	}
	for(i=1;i<(1<<n);i++){
		for(j=i;j;j=i&(j-1)){
			if((!dp[i-j])&&i!=j) continue;
			if(!f[j].size()) continue;
			dp[i]=j;
			break;
		}
	}
	if(!dp[(1<<n)-1]){
		cout<<"No";
		return 0;
	}
	int p=(1<<n)-1;
	while(p){
		for(i=0;i<f[dp[p]].size();i++)
			ans.push_back(f[dp[p]][i]);
		p-=dp[p];
	}
	cout<<"Yes"<<endl;
	sort(ans.begin(),ans.end());
	for(i=0;i<ans.size();i++) pos[ans[i].to]=i+1;
	for(i=0;i<ans.size();i++) cout<<ans[i].val<<" "<<pos[i+1]<<endl;
	return 0;
}
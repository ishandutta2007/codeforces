#include<bits/stdc++.h>
using namespace std;
 
#define MAX 1000002
 
int n;
long long int k;
 
long long int gcd(long long int a,long long int b){
	if(a<b)swap(a,b);
	while(b){
		swap(a,b);
		b%=a;
	}
	return a;
}
 
long long int ar[MAX];
 
vector<long long int> pr;
 
bool cost[1<<11];
vector<long long int> vv;
 
long long int dp[1<<11][12];
 
unordered_map<long long int,vector<long long int> > m2;
 
inline void calc(long long int num,int pos,int sub,long long int cur){
	if(pos==pr.size()){
		cost[sub]=true;
		return;
	}
	calc(num,pos+1,sub,cur);
	while(num%pr[pos]==0LL&&cur<=k/pr[pos]){
		num/=pr[pos];
		cur*=pr[pos];
	}
	if(num%pr[pos]){
		calc(num,pos+1,sub|(1<<pos),cur);
	}
}
 
int main(){
	cin>>n>>k;
	for(int i=0;i<(1<<11);i++){
		cost[i]=LLONG_MAX;
	}
	long long int gc=0;
	for(int i=0;i<n;i++){
		long long int a;
		scanf("%lld",&a);
		ar[i]=a;
		gc=gcd(gc,a);
	}
	for(int i=0;i<n;i++){
		long long int a;
		scanf("%lld",&a);
		vv.push_back(a);
	}
	for(long long int i=2;i*i<=gc;i++){
		if(gc%i==0){
			pr.push_back(i);
			while(gc%i==0)gc/=i;
		}
	}
	if(gc>1LL)pr.push_back(gc);
	int m=pr.size();
	sort(pr.begin(),pr.end());
	for(int i=0;i<n;i++){
		int mask=0;
		long long int U=1;
		for(int j=0;j<pr.size();j++){
			while(ar[i]%pr[j]==0LL){
				U*=pr[j];
				ar[i]/=pr[j];
			}
		}
		m2[U].push_back(vv[i]);
	}
	for(int i=0;i<(1<<m);i++){
		for(int j=0;j<=m;j++)dp[i][j]=LLONG_MAX;
	}
	dp[0][0]=0;
	for(auto &el:m2){
		for(int i=0;i<(1<<m);i++)cost[i]=false;
		calc(el.first,0,0,1);
		for(int i=0;i<m;i++){
			for(int j=0;j<(1<<m);j++){
				if((j>>i)&1){
					cost[j^(1<<i)]|=cost[j];
				}
			}
		}
		auto &g=el.second;
		sort(g.begin(),g.end());
		for(int idx=0;idx<g.size()&&idx<m;idx++){
			bool upd=false;
			for(int i=(1<<m)-1;i>=0;i--){
				for(int k=m-1;k>=0;k--){
					if(dp[i][k]==LLONG_MAX)continue;
					for(int j=i+1;j<(1<<m);j++,j|=i){
						int cov=(j^i);
						if(cost[cov]==false)continue;
						if(dp[j][k+1]>dp[i][k]+g[idx]){
							upd=true;
						}
						dp[j][k+1]=min(dp[j][k+1],dp[i][k]+g[idx]);
					}
				}
			}
			if(upd==false)break;
		}
	}
	long long int ans=LLONG_MAX;
	for(int i=0;i<=m;i++){
		long long int z=dp[(1<<m)-1][i];
		if(z!=LLONG_MAX){
			ans=min(ans,z*i);
		}
	}
	if(ans==LLONG_MAX){
		ans=-1;
	}
	printf("%lld\n",ans);
	return 0;
}
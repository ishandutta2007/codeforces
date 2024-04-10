#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAX_N=2e5+5;
vector<ll> key;
ll l[MAX_N],r[MAX_N],sum[MAX_N*2],cnt[MAX_N];
int main(){
	int n; scanf("%d",&n),key.clear();
	for(int i=1;i<=n;++i) scanf("%I64d%I64d",&l[i],&r[i]),r[i]+=1;
	for(int i=1;i<=n;++i) key.push_back(l[i]),key.push_back(r[i]);
	sort(key.begin(),key.end());
	key.erase(unique(key.begin(),key.end()),key.end());
	for(int i=1;i<=n;++i){
		l[i]=lower_bound(key.begin(),key.end(),l[i])-key.begin();
		r[i]=lower_bound(key.begin(),key.end(),r[i])-key.begin();
	}
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;++i) sum[l[i]]+=1,sum[r[i]]-=1;
	for(int i=1;i<key.size();++i) sum[i]=sum[i-1]+sum[i];
	for(int i=0;i<key.size()-1;++i) cnt[sum[i]]+=key[i+1]-key[i];
	for(int i=1;i<=n;++i) printf("%I64d ",cnt[i]);
	return 0;  
}
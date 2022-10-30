#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<map>
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:-x;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
vector<int>vec[200010];
set<int>st;
int n;
int a[200010];
int sum[200010];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();vec[a[i]].pb(i);
	}
	int maxn,cnt;maxn=0,cnt=0;
	for(int i=1;i<=n;++i){
		if(vec[i].size()>vec[maxn].size()){
			maxn=i,cnt=1;
		}
		else if(vec[i].size()==vec[maxn].size()) ++cnt;
	}
	if(cnt>1){
		printf("%d\n",n);
		return 0;
	}
	for(int i=1;i<=n+1;++i){
		sum[i]=sum[i-1]+(a[i]==maxn);
		if(a[i]==maxn) st.insert(i);
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(i==maxn) continue ;
		if(vec[i].empty()) continue ;
		vector<int>v;
		for(int j:vec[i]){
			auto it=st.lower_bound(j);
			if(it!=st.begin()){
				--it;
				v.pb(*it);st.erase(it);
			}
			it=st.lower_bound(j);
			if(it!=st.end()){
				v.pb(*it);st.erase(it);
			}
			it=st.lower_bound(j);
			if(it!=st.begin()){
				--it;
				v.pb(*it);st.erase(it);
			}
			it=st.lower_bound(j);
			if(it!=st.end()){
				v.pb(*it);st.erase(it);
			}
		}
		auto it=st.lower_bound(vec[i][0]);
		if(it!=st.begin()){
			--it;
			v.pb(*it);st.erase(it);
		}
		it=st.lower_bound(vec[i].back());
		if(it!=st.end()){
			v.pb(*it);st.erase(it);
		}
		vector<int> tmp=v;
		for(int j:vec[i]){
			v.pb(j);
		}
		v.pb(n+1);
		sort(v.begin(),v.end());
		map<int,int>Map;
		Map[0]=0;
		int s=0;
		for(int j=0;j<v.size();++j){
//			printf("pos:%d,s:%d\n",v[j],sum[v[j]-1]+s);
			if(Map.count(sum[v[j]-1]+s)){
				ans=max(ans,v[j]-Map[sum[v[j]-1]+s]-1);
			}
			if(a[v[j]]==i) --s;
//			printf("S:%d\n",sum[v[j]]+s);
			if(Map.count(sum[v[j]]+s)==0) Map[sum[v[j]]+s]=v[j];
		}
		for(int j:tmp) st.insert(j);
//		printf("i:%d,ans:%d\n",i,ans);
	}
	printf("%d\n",ans);
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,t;
set<pair<int,int> >st;
map<int,int>num;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		num.clear();
		for(int i=1,x;i<=n;i++)
			scanf("%d",&x),num[x]++;
		st.clear();
		for(auto it:num)st.insert({it.second,it.first});
		int ans=1e9;
		int cnt=0;
		int now=k,rem=st.size();
		while(!st.empty()&&(*st.begin()).first<=now)
			now-=(*st.begin()).first,rem--,st.erase(st.begin());
		for(int i=0;i<=n;i++){
			if(i-cnt>k)continue;
			ans=min(ans,rem);
			if(num[i]){
				cnt++;
				if(st.count(make_pair(num[i],i))){
					rem--,st.erase({num[i],i});
				}else now+=num[i];
				while(!st.empty()&&(*st.begin()).first<=now)
					now-=(*st.begin()).first,rem--,st.erase(st.begin());
			}
		}
		printf("%d\n",ans);
	}
}
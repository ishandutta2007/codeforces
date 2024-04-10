#include<bits/stdc++.h>
using namespace std;
const int N=2e6+6,M=1e6+2;
vector<int>vec[N];
int T,n,m,ans;
string s[N];
int work(){
	set<int>st;
	for(int i=-m;i<=n;++i){
		int last=1e9;
		while(vec[i+M].size()){
			int x=vec[i+M].back();
			vec[i+M].pop_back();
			if(last<=x)continue;
			auto it=st.upper_bound(x);
			if(it==st.begin()){
				last=0;
				st.insert(x);
			}else{
				--it;
				last=*it;
				st.erase(it);
				st.insert(x);
			}
		}
	}
	return st.size();
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	for(cin>>T;T--;){
		cin>>n>>m;
		for(int i=1;i<=n;++i)
			cin>>s[i];
		for(int i=1;i<=n;++i)
			for(int j=0;j<m;++j)
				if((i+j)%2&&s[i][j]=='1')
					vec[i-j+M].emplace_back(i+j);
		ans=work();
		for(int i=1;i<=n;++i)
			for(int j=0;j<m;++j)
				if((i+j)%2==0&&s[i][j]=='1')
					vec[i-j+M].emplace_back(i+j);
		ans+=work();
		cout<<ans<<'\n';
	}
	return 0;
}
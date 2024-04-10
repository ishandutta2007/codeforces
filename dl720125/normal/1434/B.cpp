#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

int n,ans[100010],pos[100010],x[200010];
char ch[200010];
set<pair<int,int> > s;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int cnt=0;
	for(int i=1;i<=2*n;i++){
		cin>>ch[i];
		if(ch[i]=='+'){
			cnt++;
			s.insert(make_pair(i,cnt));
		}
		else{
			cin>>x[i];
			pos[x[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		set<pair<int,int> >::iterator it=s.lower_bound(make_pair(pos[i],0));
		if(it==s.begin()){
			cout<<"NO\n";return 0;
		}
		it--;
		ans[it->second]=i;
		s.erase(it);
	}
	set<int> s;
	cnt=0;
	for(int i=1;i<=2*n;i++){
		if(ch[i]=='+'){
			cnt++;
			s.insert(ans[cnt]);
		}
		else{
			if(s.empty()){
				cout<<"NO\n";return 0;
			}
			if(*s.begin()!=x[i]){
				cout<<"NO\n";return 0;
			}
			s.erase(s.begin());
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n"; 
	return 0;
}
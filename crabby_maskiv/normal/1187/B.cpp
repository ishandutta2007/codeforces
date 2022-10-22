#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
string str;
vector<int> v[200];
int cnt[200];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	cin>>str;str=" "+str;
	for(i=1;i<=n;i++) v[str[i]].push_back(i);
	cin>>m;
	while(m--){
		memset(cnt,0,sizeof(cnt));
		string s;cin>>s;
		int len=s.length();
		s=" "+s;
		for(i=1;i<=len;i++) cnt[s[i]]++;
		int ans=0;
		for(i='a';i<='z';i++){
			if(!cnt[i]) continue;
			ans=max(ans,v[i][cnt[i]-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
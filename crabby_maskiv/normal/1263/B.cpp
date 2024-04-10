#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=15;
int n,m;
map<string,int> mp;
string s[N];
int main(){
	int i,j,k;
	int T;cin>>T;
	while(T--){
		cin>>n;
		mp.clear();
		for(i=1;i<=n;i++){
			cin>>s[i];
			mp[s[i]]++;
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(mp[s[i]]<=1) continue;
			for(j=0;j<4;j++){
				for(k=0;k<10;k++){
					string t=s[i];
					t[j]=k+'0';
					if(mp[t]==0){
						ans++;
						mp[s[i]]--;
						mp[t]++;
						s[i]=t;
						break;
					}
				}
				if(k<10) break;
			}
		}
		cout<<ans<<endl;
		for(i=1;i<=n;i++) cout<<s[i]<<endl;
	}
	return 0;
}
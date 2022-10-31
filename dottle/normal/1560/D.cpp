#include<bits/stdc++.h>
#define int long long
const int N=64;
using namespace std;

string a[N],s;
int t,p[N];

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<N;i++)
		a[i]=to_string(1ull<<i);
	while(t--){
		cin>>s;
		memset(p,0,sizeof(p));
		for(int j=0;j<s.size();j++){
			for(int i=0;i<N;i++)
				if(p[i]<a[i].size()&&a[i][p[i]]==s[j])
					p[i]++;
		}
		int ans=114514;
		for(int i=0;i<N;i++)
			ans=min(ans,(int)(s.size()+a[i].size()-p[i]*2));
		cout<<ans<<endl;
	}
}
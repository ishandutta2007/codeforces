#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
char a[N],b[N];
int f[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		cin>>(a+1)>>(b+1);
		vector<int> ans;
		for(i=1;i<=n;i++){
			if(i&1) f[i]=i/2+1;
			else f[i]=n-i/2+1;
		}
		for(i=1;i<=n;i++){
			if(i&1){
				if(a[f[i]]==b[n-i+1]) ans.push_back(1);
			}
			else{
				if(a[f[i]]!=b[n-i+1]) ans.push_back(1);
			}
			ans.push_back(n-i+1);
		}
		cout<<ans.size()<<" ";
		for(auto x:ans) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
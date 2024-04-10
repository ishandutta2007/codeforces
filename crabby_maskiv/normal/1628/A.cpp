#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
int a[N];
int c[N],vis[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) c[a[i]]++;
		int la=1,p=0;
		vector<int> ans;
		for(i=1;i<=n;i++){
			vis[a[i]]=1;
			while(vis[p]) p++;
			if(!c[p]){
				ans.push_back(p);
				for(j=la;j<=i;j++){
					c[a[j]]--;
					vis[a[j]]=0;
				}
				p=0;
				la=i+1;
			}
		}
		cout<<ans.size()<<endl;
		for(auto x:ans) cout<<x<<" ";
		cout<<endl;
		for(i=0;i<=n;i++) c[i]=vis[i]=0;
	}
	return 0;
}
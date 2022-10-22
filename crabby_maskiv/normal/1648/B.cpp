#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e6+5;
int n,m;
int a[N],b[N],s[N];
void solve(){
	int i,j;
	for(i=1;i<=n;i++) b[a[i]]=1;
	for(i=1;i<=m;i++) s[i]=s[i-1]+b[i];
	for(i=1;i<=m;i++){
		if(!b[i]) continue;
		for(j=i;j<=m;j+=i){
			if(!b[j/i]&&(s[min(m,j+i-1)]-s[j-1])){
				cout<<"No"<<endl;
				return;
			}
		}
	}
	cout<<"Yes"<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		solve();
		for(i=1;i<=m;i++) b[i]=s[i]=0;
	}
	return 0;
}
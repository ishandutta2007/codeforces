#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define endl '\n'
const int N=2e5+10;
int a[N];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k,m;
		cin>>n>>k>>m;
		for(int i=0;i<m;i++){
			cin>>a[i];
			a[i]--;
		}
		if((n-m)%(k-1)){
			cout<<"NO"<<endl;
			continue;
		}
		if(n==m){
			cout<<"YES"<<endl;
			continue;
		}
		int cnt=0;
		int id=0;
		int s=-1;
		for(int i=0;i<n;i++){
			if(id<m&&a[id]==i){
				id++;
			}else{
				cnt++;
			}
			if(cnt==(k-1)/2){
				s=i;
				break;
			}
		}
		int e=-1;
		id=m-1;
		cnt=0;
		for(int i=n-1;i>=0;i--){
			if(id>=0&&a[id]==i){
				id--;
			}else{
				cnt++;
			}
			if(cnt==(k-1)/2){
				e=i;
				break;
			}
		}
		bool ans=false;
		id=0;
		for(int i=0;i<n;i++){
			if(id<m&&a[id]==i){
				if(i>=s && i<=e){
					ans=true;
				}
				id++;
			}
		}
		if(ans){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
}
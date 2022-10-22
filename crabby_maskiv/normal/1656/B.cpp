#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,k;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>k;
		for(i=1;i<=n;i++) cin>>a[i];
		set<int> s;
		for(i=1;i<=n;i++) s.insert(a[i]);
		for(i=1;i<=n;i++){
			if(s.find(a[i]+k)!=s.end()){
				cout<<"YES"<<endl;
				break;
			}
		}
		if(i>n){
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
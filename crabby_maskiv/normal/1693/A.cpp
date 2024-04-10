#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
ll a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<=n;i++) a[i]+=a[i-1];
		if(a[n]!=0) cout<<"No"<<endl;
		else{
			for(i=1;i<=n;i++){
				if(a[i]<0||(i>1&&a[i]!=0&&a[i-1]==0)){
					cout<<"No"<<endl;
					break;
				}
			}
			if(i>n) cout<<"Yes"<<endl;
		}
	}
	return 0;
}
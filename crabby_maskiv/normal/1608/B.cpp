#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,a,b;

int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>a>>b;
		if(a+b>n-2||a>b+1||b>a+1){
			cout<<-1<<endl;
			continue;
		}
		if(a==b){
			cout<<1<<" ";
			for(i=1;i<=a;i++){
				cout<<n-i+1<<" ";
				cout<<i+1<<" ";
			}
			for(i=a+2;i<=n-a;i++) cout<<i<<" ";
		}
		else if(a>b){
			for(i=1;i<=a;i++){
				cout<<i<<" ";
				cout<<n-i+1<<" ";
			}
			for(i=n-a;i>a;i--) cout<<i<<" ";
		}
		else{
			for(i=1;i<=b;i++){
				cout<<n-i+1<<" ";
				cout<<i<<" ";
			}
			for(i=b+1;i<=n-b;i++) cout<<i<<" ";
		}
		cout<<endl;
	}
	return 0;
}
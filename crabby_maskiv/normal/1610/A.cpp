#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;

int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		if(n==1&&m==1) cout<<0<<endl;
		else if(n==1||m==1) cout<<1<<endl;
		else cout<<2<<endl;
	}
	return 0;
}
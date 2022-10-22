#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n;
int a[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++){
			int x;cin>>x;
			if(x<0) x=-x;
			if(i&1) cout<<-x<<" ";
			else cout<<x<<" ";
		}
		cout<<endl;
	}
	return 0;
}
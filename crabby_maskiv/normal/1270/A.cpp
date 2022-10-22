#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int n,m;
int a[N],b[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		int k1,k2,mx1=0,mx2=0;
		cin>>n>>k1>>k2;
		for(i=1;i<=k1;i++){
			cin>>a[i];mx1=max(mx1,a[i]);
		}
		for(i=1;i<=k2;i++){
			cin>>b[i];mx2=max(mx2,b[i]);
		}
		cout<<(mx1>mx2?"YES":"NO")<<endl;
	}
	return 0;
}
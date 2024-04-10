#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n,m;
int a[N];
int main(){
	int i,j;
	cin>>n>>m;
	int c[2]={0,0};
	for(i=1;i<=n;i++){
		cin>>a[i];c[a[i]]++;
	}
	for(i=1;i<=m;i++){
		int op,x;cin>>op>>x;
		if(op==1){
			c[a[x]]--;
			a[x]^=1;
			c[a[x]]++;
		}
		else{
			if(x>c[1]) cout<<0<<endl;
			else cout<<1<<endl;
		}
	}
	return 0;
}
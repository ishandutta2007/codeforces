#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,m,q;string s[N],t[N];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=m;i++)cin>>t[i];
	scanf("%d",&q);
	for(int i=1,x;i<=q;i++){
		scanf("%d",&x);
		cout<<s[(x-1)%n+1]<<t[(x-1)%m+1]<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char a[N],b[N];
int is[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;
	cin>>n>>m>>T;
	cin>>(a+1);
	cin>>(b+1);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i+j-1]!=b[j])
				break;
		}
		if(j>m) is[i]=1;
	}
	for(i=1;i<=n;i++) is[i]+=is[i-1];
	while(T--){
		int x,y;cin>>x>>y;
		if(y-x+1<m) cout<<0<<endl; 
		else cout<<is[y-m+1]-is[x-1]<<endl;
	}
	return 0;
}
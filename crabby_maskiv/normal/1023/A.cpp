#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;
int n,m;
char a[N],b[N];
int main(){
//	freopen("07.in","r",stdin);
//	freopen("test.out","w",stdout);
	int i,j;
	cin>>n>>m>>(a+1)>>(b+1);
	if(n>m+1){
		cout<<"NO";
		return 0;
	}
	bool flag=0;
	for(i=1;i<=n;i++) if(a[i]=='*') flag=1;
	if(!flag&&n!=m){
		cout<<"NO";
		return 0;
	}
	for(i=1;i<=n&&a[i]!='*';i++){
		if(a[i]!=b[i]){
			cout<<"NO";
			return 0;
		}
	}
	for(i=n;i&&a[i]!='*';i--){
		if(a[i]!=b[m-n+i]){
			cout<<"NO";
			return 0;
		}
	}
	cout<<"YES";
	return 0;
}
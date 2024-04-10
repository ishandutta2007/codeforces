#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=998244353;
char a[N];
int s[N];
int n,m;
int main(){
	int i,j;
	int dep=0;
	cin>>n>>m>>(a+1);
	for(i=n;i;i--)
		s[i]=s[i+1]+(a[i]==')');
	for(i=1;i<=n;i++){
		cout<<a[i];
		if(a[i]=='(') dep++;
		if(a[i]==')') dep--;
		if(dep==m-i&&s[i+1]>=dep) break;
	}
	int cnt=m-i;
	while(cnt--) cout<<')';
	return 0;
}
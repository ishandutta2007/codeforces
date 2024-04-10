#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=305;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char a[N];
string ans[N];
int len,pos,cnt;
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		cin>>(a+1);
		if(n==2&&a[1]>=a[2]){
			cout<<"NO"<<endl;
			continue;
		}
		cout<<"YES"<<endl;
		cout<<2<<endl;
		cout<<a[1]<<" ";
		for(i=2;i<=n;i++) cout<<a[i];
		cout<<endl;
	}
	return 0;
}
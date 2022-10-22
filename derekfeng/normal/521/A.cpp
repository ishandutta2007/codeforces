#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int n,cnt=0;
ll ans=1;
int a[203];
char c;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c;
		if(c=='A')a[0]--;
		if(c=='C')a[1]--;
		if(c=='G')a[2]--;
		if(c=='T')a[3]--;
	}
	sort(a,a+4);
	while(a[cnt]==a[0])cnt++;
	for(int i=1;i<=n;i++)ans=ans*cnt%M;
	cout<<ans;
}
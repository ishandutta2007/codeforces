#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=10005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
char a[N];
char base[10]={'a','e','i','o','u'};
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	int k1,k2;
	for(i=5;i<=100;i++){
		if(i*i>n) break;
		if(n%i==0){
			k1=i;
			k2=n/i;
			break;
		}
	}
	if(i*i>n){
		cout<<-1;
		return 0;
	}
	for(i=1;i<=k2;i++){
		int p=(i-1)%5;
		for(j=1;j<=k1;j++){
			cout<<base[p];
			p++;
			p%=5;
		}
	}
	return 0;
}
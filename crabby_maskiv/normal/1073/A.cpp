#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
char a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	cin>>(a+1);
	for(i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			cout<<"YES"<<endl;
			cout<<a[i]<<a[i+1];
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}
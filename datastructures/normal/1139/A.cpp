#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;
int n;
string x;
ll ans;
int main(){
//	freopen("1139A.in","r",stdin);
//	freopen("1139A.out","w",stdout);
	cin>>n>>x;
	for (int i=0;i<n;i++)
		ans+=(1ll-(x[i]-'0')%2)*(i+1); 
	cout<<ans<<endl;
}
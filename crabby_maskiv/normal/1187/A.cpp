#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;

int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	while(n--){
		int x,y,z;cin>>x>>y>>z;
		cout<<max(x-y,x-z)+1<<endl;
	}
	return 0;
}
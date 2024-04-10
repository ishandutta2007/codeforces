#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int main(){
	int i,j;
	cin>>n;
	if(n==1) cout<<-1;
	else cout<<n<<" "<<n+1<<" "<<n*(n+1);
	return 0;
}
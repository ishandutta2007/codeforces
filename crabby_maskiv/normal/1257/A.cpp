#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;

int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m>>i>>j;
		if(i>j) swap(i,j);
		cout<<min(j-i+m,n-1)<<endl;
	}
	return 0;
}
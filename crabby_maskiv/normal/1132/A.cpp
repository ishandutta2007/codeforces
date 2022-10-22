#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
ll a,b,c,d; 
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>a>>b>>c>>d;
	if(a!=d){
		cout<<0;
		return 0;
	}
	if(!a&&c){
		cout<<0;
		return 0;
	}
	cout<<1;
	return 0;
}
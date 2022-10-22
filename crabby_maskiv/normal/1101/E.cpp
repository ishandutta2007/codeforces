#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int mxx,mxy;
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n;
	while(n--){
		char op;int x,y;
		cin>>op>>x>>y;
		if(x<y) swap(x,y);
		if(op=='+'){
			mxx=max(mxx,x);
			mxy=max(mxy,y);
		} 
		else{
			if(mxx<=x&&mxy<=y) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	} 
	return 0;
}
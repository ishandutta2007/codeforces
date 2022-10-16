#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
typedef long long ll;
typedef double db;
using namespace std;
const int MAXN=100;
int T,n,a[MAXN],ans;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		rep(i,1,n)cin>>a[i];
		ans=0;
		rep(i,1,n-1){
			//ii+1
			int tmp=a[i];
			while(tmp*2<a[i+1]){
				ans++;
				tmp*=2;
			} 
			int tmp2=a[i+1];
			while(tmp2*2<tmp){
				ans++;
				tmp2*=2;
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
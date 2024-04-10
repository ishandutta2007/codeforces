#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int n,b,k,a,ans;

int main(){
	cin>>b>>k;
	rep(i,1,k-1){
		cin>>a;
		ans=(ans+a*b)%2;
	}
	cin>>a;
	ans=(ans+a)%2;
	if(ans%2)puts("odd");
	else puts("even");
	return 0;
}
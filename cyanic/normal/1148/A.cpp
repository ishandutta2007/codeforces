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



int main(){

	ll a,b,c;
	cin>>a>>b>>c;
	a=min(a,b+1);
	b=min(b,a+1);
	cout<<(c*2+a+b)<<endl;


	return 0;
}
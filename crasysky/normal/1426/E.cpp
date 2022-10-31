#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define mp make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=2e5+5;
int main(){
	int n,a1,a2,a3,b1,b2,b3;
	cin>>n>>a1>>a2>>a3>>b1>>b2>>b3;
	cout<<n-min(n,min(a1+a2+b2+b3,min(a1+a3+b1+b2,a2+a3+b1+b3)))<<" ";
	cout<<min(a1,b2)+min(a2,b3)+min(a3,b1)<<endl;
	return 0;
}
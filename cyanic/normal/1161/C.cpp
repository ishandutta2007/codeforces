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

int a[55],n;

int main(){
	cin>>n;
	rep(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]==a[n/2+1])puts("Bob");
	else puts("Alice");
	return 0;
}
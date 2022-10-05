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

const int N=1005;
int a[N][N],b[N][N];
int A[2][N],B[2][N];
int n,m;

int main(){
	cin>>n>>m;
	rep(i,1,n)rep(j,1,m){
		cin>>a[i][j];
		A[0][i]^=a[i][j];
		A[1][j]^=a[i][j];
	}
	rep(i,1,n)rep(j,1,m){
		cin>>b[i][j];
		B[0][i]^=b[i][j];
		B[1][j]^=b[i][j];
	}
	rep(i,1,n)if(A[0][i]!=B[0][i])
		return puts("No"),0;
	rep(j,1,m)if(A[1][j]!=B[1][j])
		return puts("No"),0;
	puts("Yes");
	return 0;
}
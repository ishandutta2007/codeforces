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

const int N=1000005;
int t[N],f[N][3][3],n,m,x;

inline void upd(int &a,int b){
	if(b<a)a=b;
}

int main(){
	cin>>n>>m;
	rep(i,1,n){
		cin>>x;
		t[x]++;
	}
	memset(f,0x3f,sizeof f);
	f[0][0][0]=0;
	rep(i,1,m)rep(a,0,2)rep(b,0,2)rep(c,0,2)
		if(a+b+c<=t[i])
			upd(f[i][b][c],f[i-1][a][b]+(t[i]-a-b-c)%3);
	printf("%d\n",(n-f[m][0][0])/3);
	return 0;
}
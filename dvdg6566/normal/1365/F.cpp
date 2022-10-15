#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
const int MAXN=510;

int dp[MAXN][MAXN];
int N,T;
int A[MAXN];
int B[MAXN];

// int ask(int x,int y,int len){
// 	if(len==0)return 1;
// 	if(dp[x][y]!=-1)return dp[x][y];
// 	// cerr<<x<<' '<<y<<' '<<len<<'\n';
// 	// int used = N/2-len;
// 	int tx=B[len];
// 	int ty=B[N+1-len];

// 	if (A[x] == tx && A[y+len-1] == ty){
// 		if(ask(x+1,y,len-1))return 1;
// 	}
// 	if (A[y+len-1] == tx && A[x] == ty){
// 		if(ask(x+1,y,len-1))return 1;
// 	}
// 	if (A[x+len-1] == tx && A[y] == ty){
// 		if(ask(x,y+1,len-1))return 1;
// 	}
// 	if (A[y] == tx && A[x+len-1] == ty){
// 		if(ask(x,y+1,len-1))return 1;
// 	}
// 	return 0;
// }

map<pi,int> M;

int main(){
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=1;i<=N;++i)cin>>A[i];
		for(int i=1;i<=N;++i)cin>>B[i];

		for(int i=1;i<=N/2;++i){
			int a=B[i];
			int b=B[N+1-i];
			if(b<a)swap(a,b);
			M[mp(a,b)]++;
		}
		int fail=0;
		for(int i=1;i<=N/2;++i){
			int a=A[i];
			int b=A[N+1-i];
			if(b<a)swap(a,b);
			M[mp(a,b)]--;
			if(M[mp(a,b)] < 0){
				fail=1;
				break;
			}
		}
		if(N%2 && A[N/2+1] != B[N/2+1]){
			fail=1;
		}
		M.clear();
		if(fail)cout<<"no\n";
		else cout<<"yes\n";
		// for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)dp[i][j]=-1;
		// if(N%2==1){
		// 	int t=ask(1,(N+3)/2,N/2);
		// 	if(A[(N+1)/2]!=B[(N+1)/2])t=0;
		// 	if(t)cout<<"yes\n";
		// 	else cout<<"no\n";
		// 	// cerr<<1<<' '<<(N+3)/2<<' '<<N/2<<'\n';
		// 	// cout<<ask(1, (N+3)/2, )
		// }else{
		// 	int t=ask(1,N/2+1,N/2);
		// 	if(t)cout<<"yes\n";
		// 	else cout<<"no\n";
		// }
	}
}
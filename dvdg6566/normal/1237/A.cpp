#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define MAXN 210000
#define INF 1e9
#define MAXL 20

int N;
int A[MAXN];
int O[MAXN];
int c;

int main(){
	cin>>N;
	for (int i=1;i<=N;++i)cin>>A[i];
	for (int i=1;i<=N;++i){
		if (A[i] %2 == 0){
			O[i] = A[i]/2;
		}else if (A[i] > 0){
			O[i] = A[i]/2;
			++c;
		}else{
			O[i] = -((1-A[i])/2);
			++c;
		}
	}
	c /= 2;
	for (int i=1;i<=N;++i)if(c > 0){
		if (abs(A[i])%2 == 1){
			if (A[i] < 0){
				O[i] = -((-A[i])/2);
			}else{
				O[i] = (A[i]+1)/2;
			}
			--c;
		}
	}
	for (int i=1;i<=N;++i)cout<<O[i]<<'\n';
}
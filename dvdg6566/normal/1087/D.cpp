#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef double dl;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define INF 1000000000
#define SZ(x) x.size()
#define ALL(x) x.begin(),x.end()

int oe[100100];
int N,a,b;
double cnt, S;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin >> N >> S;
  for (int i=1;i<N;++i){
    cin>>a>>b;
    oe[a]++;
    oe[b]++;
  }
  for (int i=1;i<=N;++i)if (oe[i] == 1)++cnt;
  printf("%.9lf",S*2/cnt);
}
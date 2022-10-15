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

int a,b;

int main(){
  ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>a>>b;
  for (int i=b-1;i>=1;--i){
    if (a%i == 0){
      cout << (a/i) * b+i;
      return 0;
    }
  }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (int)x.size()
#define f first
#define s second
const int MAXN=266100;
const int MAXK=19;
const int INF = 1e9;

ll a,b,c,d,e,f,g;
ll A[MAXN];
ll B[MAXN];
vi V[MAXN];

int main(){
  cin>>g;
  while(g--){
    cin>>a>>b>>c;
    ll d=0;
    while(max(a,b)<=c){
      ++d;
      if(a<b)swap(a,b);
      b+=a;
    }
    cout<<d<<'\n';
  }
}
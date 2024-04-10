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
string S="codeforces";

bool works(){
  ll h=1;
  for (int i=1;i<=10;++i)h*=A[i];
  if(h>=a)return 1;
  return 0;
}

int main(){
  cin>>a;
  for (int i=1;i<=10;++i)A[i]=1;
  for (int i=0;i<50;++i){
    if(works())break;
    for (int j=1;j<=10;++j){
      A[j]++;
      if(works())break;
    }
  }
  for (int i=1;i<=10;++i){
    for (int k=0;k<A[i];++k){
      cout<<S[i-1];
    }
  }
}
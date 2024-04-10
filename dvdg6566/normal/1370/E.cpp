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
const int MAXN=210000;
const int MAXK=19;
const int INF = 1e9;
const ll MOD = 998244353;

ll N,K,a,b,c,d,e,f;
vi A;
string S1,S2;
int B[2];

int main(){
  cin>>N>>S1>>S2;
  for (int i=0;i<N;++i){
    int a = S1[i]-'0';
    int b=S2[i]-'0';
    if(a==b)continue;
    A.pb(a);
  }
  int a=0;
  for (auto i:A){
    if(i==0)++a;
    else --a;
  }
  if(a){
    cout<<-1;
    return 0;
  }
  int c=0;
  for (auto i:A){
    if(B[i] == 0){
      B[i^1]++;
      ++c;
    }else{
      --B[i];
      ++B[i^1];
    }
  }
  cout<<c;
}
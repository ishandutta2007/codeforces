#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 998244353;
const ll INF = 1e9;
const ll MAXN = 200100;
typedef pair<pi,int> ppi;
#define v(x) vector<x>

string S;
int ask(string x){
  cout<<x<<endl;
  int t;cin>>t;
  if (t==0)exit(0);
  return t;
}

int L = 300;

int main(){
  string A,B;
  for (int i=0;i<L;++i)A+='a';
  for (int i=0;i<L;++i)B+='b'; 
  int a = ask(A);
  int b = ask(B);
  int x = a+b-L;
  a = L-a;
  b = L-b;
  L = a+b;
  // cerr<<a<<' '<<b<<' '<<L<<endl;
  int ori = b;
  A="";for (int i=0;i<L;++i)A+='a';
  string out;
  for (int i=0;i<L-1;++i){
    A[i] = 'b';
    int x=ask(A);
    // assert(x!=ori);
    if(x>ori){out+='a';--a;}
    else {out+='b';--b;}
    A[i] = out[i];
    ori=min(ori,x);
  }
  if (a==0)out+='b';
  else out+='a';
  ask(out);
}
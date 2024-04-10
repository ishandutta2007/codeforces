#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef pair<pi,int> pii;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(X) X.begin(),X.end()
#define SZ(X) (int)X.size()
#define MAXN 1000100
#define INF 1e9

string S;

int main(){
  cin>>S;
  reverse(ALL(S));
  while(SZ(S) && S.back() != '1')S.pop_back();
  int t = 0;
  for (auto i : S)t += (i - '0');
  if (t == 1)S.pop_back();
  cout<<(SZ(S) + 1)/2;
}
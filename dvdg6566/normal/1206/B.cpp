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
#define MAXN 200100
#define INF 1e9
ll N,a,ans,zero,pos,neg;
 
int main(){
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a;
    if (a==0)++zero;
    else if (a > 0){
      ans += a-1;
      ++pos;
    }else{
      ans += abs(a) - 1;
      ++neg;
    }
  }
  if (neg%2==0){
    cout<<zero+ans;
  }else if (zero){
    cout<<zero+ans;
  }else{
    cout<<2+ans;
  }
}
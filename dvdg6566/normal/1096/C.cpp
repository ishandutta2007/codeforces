#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

int gcd(int a, int b){
  if (b == 0)return a;
  return gcd(b,a%b);
}

int main(){
  int N,a;
  cin>>N;
  for (int i=0;i<N;++i){
    cin>>a;
    int x = 180/gcd(180,a);
    int y = x;
    while ((y - 2)*180/x < a) y += x;
    cout << y << '\n';
  }
}
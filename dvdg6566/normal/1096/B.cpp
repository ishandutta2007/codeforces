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
ll MOD = 998244353;
ll N,lind, rind;
string st;
char l,r;

int main(){
 cin>>N>>st;
 l = st[0];r = st.back();
 lind=rind=1;
 for (int i=0;i<N;++i){
   if (l == st[i])++lind;
   else break;
 }
 for (int i=N-1; i >= 0; --i){
   if (r == st[i])++rind;
   else break;
 }
 if (l == r){
   cout << lind * rind % MOD;
 }else{
   cout << (lind + rind-1) % MOD;
 }
}
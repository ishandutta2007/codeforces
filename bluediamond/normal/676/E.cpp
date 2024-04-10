#include <bits/stdc++.h>

using namespace std;

bool home=1;
typedef long long ll;

#define int ll

const int U=123456;
const int N=(int)1e5+7;
int n,k,a[N];

mt19937 rng((long long) (new char));

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);


  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("TonyStark", "r", stdin);
  } else {
    ios::sync_with_stdio(0); cin.tie(0);
  }


  cin>>n>>k;



  for (int i=0;i<=n;i++){
    string s;
    cin>>s;
    if (s=="?"){
      a[i]=U;
    }else{
      int sgn=+1,num=0,pt=0;
      while (pt<s.size()&&s[pt]=='-'){
        sgn*=-1;
        pt++;
      }
      while (pt<s.size()){
        assert('0'<=s[pt]&&s[pt]<='9');
        num=10*num+s[pt]-'0';
        pt++;
      }
      a[i]=sgn*num;
    }
  }
  /**

  P(x)=Q(x)*(x-k) => P(k)=Q(x)*(k-k)=0

  P(k)=0 => P(x)=Q(x)*(x-k)

  **/
  int cu=0;
  for (int i=0;i<=n;i++)cu+=(a[i]==U);

  if (k==0){
    if (a[0]==0||((n-cu)%2==0&&a[0]==U)){
      cout<<"Yes\n";
    }else{
      cout<<"No\n";
    }
    exit(0);
  }
  if (home){
    for (int i=0;i<=n;i++){
      if (a[i]==U){
        cout<<"UNDEFINED\n";
      }else{
        cout<<a[i]<<"\n";
      }
    }
  }


  if (cu){
    if (n&1){
      cout<<"Yes\n";
    }else{
      cout<<"No\n";
    }
    exit(0);
  }


  for (int it=1;it<=100;it++){
    int mod=rng(),cur=1,sum=0;
    for (int i=0;i<=n;i++){
      sum=(sum+cur*a[i])%mod;
      cur=(cur*k)%mod;
    }
    if (sum){
      cout<<"No\n";
      return 0;
    }
  }
  cout<<"Yes\n";

  return 0;
}
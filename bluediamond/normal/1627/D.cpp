#include <bits/stdc++.h>

using namespace std;

const int N=(int)1e6+7;
int n,f[N],sol=0;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  cin>>n;
  for (int i=1;i<=n;i++){
    int x;
    cin>>x;
    f[x]=1;
  }
  for (int i=N-1;i>=1;i--){
    int g=0;
    for (int j=i;j<N&&g!=1;j+=i){
      if(f[j]) g=__gcd(g,j/i);
    }
    if(g==1)f[i]=1;
    sol+=(f[i]==1);
  }
  cout<<sol-n<<"\n";
  return 0;
}
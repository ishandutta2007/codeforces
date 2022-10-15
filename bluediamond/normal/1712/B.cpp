#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
/// #define int long long

void print(vector<int> a) {
  ///cout << " ---> ";
  for(auto&x:a){
    cout<<x<<" ";
  }
  cout<<"\n";
}

int lcm(int a,int b){
  return a*b/__gcd(a,b);
}

int get(vector<int> a){
  int sol=0,n=(int)a.size();
  for(int i=0;i<n;i++){
    sol+=lcm(a[i],i+1);
  }
  return sol;
}

vector<int> my(int n) {
  vector<int> sol(n);
  iota(sol.begin(),sol.end(),1);
  if (n%2==0){
    for(int i=0;i+1<n;i+=2){
      swap(sol[i],sol[i+1]);
    }
  }else{
    if(n>1){
      assert(n>=3);
      for (int i=1;i+1<n;i+=2) {
        swap(sol[i],sol[i+1]);
      }

    }
  }
  return sol;
}


signed main()
{
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  int t;
  cin>>t;
  for(int tc=1;tc<=t;tc++){
    int n;
    cin>>n;
    print(my(n));
    continue;
    cout<<n<<" ";
    for (int i=1;i<n;i++) {
      cout<<i<<" ";
    }
    cout<<"\n";
  }
}
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAXN = 505050;

int N, arr[MAXN];

int modify(int l, int r) {
  if(l == r) return 0;
  if(arr[l] == arr[r]) {
    for(int i=l+1; i<r; i++)
      arr[i] = arr[l];
    return (r-l)/2;
  } else {
    int m = (l+r+1)/2;
    FOR(i,l+1,m) arr[i] = arr[l];
    FOR(i,m,r) arr[i] = arr[r];
    return (r-l-1)/2;
  }
}

int main() {
  cin>>N;
  F0R(i,N) cin>>arr[i];

  int ans = 0, lb = 0;
  F0R(i,N) {
    if(i == N-1 || arr[i] == arr[i+1]) {
      ans = max(ans, modify(lb, i));
      lb = i+1;
    }
  }
  cout<<ans<<"\n";
  F0R(i,N)  cout<<arr[i]<<(i==N-1 ? "\n" : " ");
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int min (int a, int b) {return a < b ? a : b;}
inline int max (int a, int b) {return a > b ? a : b;}
inline int max (int a, int b, int c) {return max (a,max(b,c));}
inline ll min (ll a, ll b) {return a < b ? a : b;}
inline ll max (ll a, ll b) {return a > b ? a : b;}
inline int abs (int a) {return a < 0 ? -a : a;}
vector<int> arr;
int where[300001];
vector<pii> swaps;
int main() { //use rightmost and leftmost indicies as pivots
    int n,a;
    scanf ("%d",&n);
    arr.resize(n);
    for (int x = 0; x < n; x++) {
      scanf ("%d",&arr[x]);
      where[arr[x]] = x;
    }
    for (int x = 1; x <= n; x++) {
      int curind = where[x], desired = x-1;
      if (curind == desired) continue;
      if (curind-desired >= n>>1) {
        swaps.push_back({curind+1,desired+1});
        swap(arr[curind],arr[desired]);
        where[arr[curind]] = curind;
        where[arr[desired]] = desired;
      }
      else if (curind+1 > n>>1) {
        if (x > n>>1) {
          swaps.push_back({curind+1,1});
          swap(arr[curind],arr[0]);
          swaps.push_back({1,desired+1});
          swap(arr[0],arr[desired]);
          swaps.push_back({curind+1,1});
          swap(arr[curind],arr[0]);
          where[arr[0]] = 0;
          where[arr[desired]] = desired;
          where[arr[curind]] = curind;
        }
        else {
          swaps.push_back({curind+1,1});
          swap(arr[curind],arr[0]);
          swaps.push_back({1,n});
          swap(arr[0],arr[n-1]);
          swaps.push_back({n,desired+1});
          swap(arr[n-1],arr[desired]);
          swaps.push_back({curind+1,1});
          swap(arr[curind],arr[0]);
          where[arr[0]] = 0;
          where[arr[curind]] = curind;
          where[arr[n-1]] = n-1;
          where[arr[desired]] = desired;
        }
      }
      else {
        swaps.push_back({curind+1,n});
        swap(arr[curind],arr[n-1]);
        swaps.push_back({n,desired+1});
        swap(arr[n-1],arr[desired]);
        where[arr[curind]] = curind;
        where[arr[desired]] = desired;
        where[arr[n-1]] = n-1;
      }
    }
    printf ("%d\n",swaps.size());
    for (pii p : swaps) {
      printf ("%d %d\n",p.first,p.second);
      assert(abs(p.first-p.second) >= n>>1);
    }
    return 0;
}
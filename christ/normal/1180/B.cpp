#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> arr;
int print[100001];
int main() {
  int n;
  scanf ("%d",&n);
  for (int x = 0,a; x < n; x++) {
    scanf ("%d",&a);
    if (a < 0) arr.push_back({a,x});
    else arr.push_back({-a-1,x});
  }
  sort(arr.begin(),arr.end());
  if (arr.size()&1) {
    print[arr[0].second] = -arr[0].first-1;
  }
  else {
    print[arr[0].second] = arr[0].first;
  }
  for (int x = 1; x < arr.size(); x++) {
    print[arr[x].second] = arr[x].first;
  }
  printf ("%d",print[0]);
  for (int x = 1; x < n; x++) printf (" %d",print[x]);
  printf ("\n");
  return 0;
}
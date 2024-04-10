#include <bits/stdc++.h>
using namespace std;
int prediff[200001], sufdiff[200001];
bool presame[200001], sufsame[200001];
vector<pair<int,int>> arr;
int main() {
  int n;
  scanf ("%d",&n);
  if (n <= 3) return !printf ("1\n");
  arr.resize(n);
  for (int x = 0;x<n;x++)scanf("%d",&arr[x].first),arr[x].second=x+1;
  sort(arr.begin(),arr.end());
  for (int x = 1; x < n; x++) {
    prediff[x] = arr[x].first - arr[x-1].first;
    presame[x] = x == 1 || (prediff[x] == prediff[x-1] && presame[x-1]);
  }
  for (int x = n-2; x >= 0; x--) {
    sufdiff[x] = arr[x].first - arr[x+1].first;
    sufsame[x] = x==n-2||(sufdiff[x] == sufdiff[x+1] && sufsame[x+1]);
  }
  if (presame[n-2]) return !printf("%d\n",arr[n-1].second);
  if (sufsame[1]) return !printf ("%d\n",arr[0].second);
  if (presame[n-3] && prediff[n-3]==arr[n-1].first-arr[n-3].first) return !printf ("%d\n",arr[n-2].second);
  if (sufsame[2] && sufdiff[2]==arr[0].first-arr[2].first) return !printf ("%d\n",arr[1].second);
  for (int x = 2; x < n-2; x++) { //consider deleting x
    if (presame[x-1] && sufsame[x+1] && prediff[x-1] == -sufdiff[x+1] && arr[x+1].first-arr[x-1].first==prediff[x-1]) return !printf ("%d\n",arr[x].second);
  }
  printf ("-1\n");
  return 0;
}
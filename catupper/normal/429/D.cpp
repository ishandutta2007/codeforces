#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define INF (1LL << 60)
pair<int, int> points[1000000] ;
 
long long int dist(int a, int b){
  long long int x = points[a].first - points[b].first;
  long long int y = points[a].second - points[b].second;
  return x * x + y * y;
}
 
long long int sq(int x){
  return x * x;
}
 
void sort_in_y(int l, int mid, int r){
  pair<int, int> tmp[r - l];
  int lps = l, rps = mid, ps = 0;
  while(lps < mid || rps < r){
    if(lps == mid || rps != r && points[lps].second > points[rps].second)
      tmp[ps++] = points[rps++];
    else
      tmp[ps++] = points[lps++];
  }
  for(int i = l;i < r;i++){
    points[i] = tmp[i - l];
  }
}
 
long long int solve(int l, int r){
  if(r - l <= 1)return INF;
  int mid = (l + r) / 2;
  int center = points[mid].first;
  long long int limit = min(solve(l, mid), solve(mid, r));
  sort_in_y(l, mid, r);
  vector<int> areas;
  for(int i = l;i < r;i++){
    if(sq(points[i].first - center) >= limit)continue;
    for(int j = areas.size() - 1;j >= 0;j--){
      if(sq(points[areas[j]].second - points[i].second) >= limit)break;
      limit = min(limit, dist(i, areas[j]));
    }
    areas.push_back(i);
  }
  return limit;
}
 
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0;i < n;i++){
		points[i].first = i;
    scanf("%d", &points[i].second);
		if(i)points[i].second += points[i - 1].second;
  }
  sort(points, points + n);
  printf("%lld\n", solve(0, n));
  return 0;
}
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 1000000+123;
ll n , m;
std::vector<pair<int,int> > v;
int a[maxn];
int t[maxn];
int res[maxn];
int tmp[maxn];
int ans,last;
int main(int argc, char const *argv[]) {
 std::cin >> n >> m;
 for(int i=1;i<=n;i++) {
   std::cin >> a[i] >> t[i];
 }
 int l = 0;
 int r = n + 1;
 while(l != r - 1) {
   int mid = (l+r) >> 1;
   int cnt = 0;
   for(int i = 1;i<=n;i++) {
     if(mid <= a[i]) {
       tmp[++cnt] = t[i];
     }
   }
   ans = 0;
   last = m;
   sort(tmp+1,tmp+1+cnt);
   for(int i=1;i<=cnt;i++) {
     if(tmp[i] <= last) {
       ans ++;
       last = last - tmp[i];
     }
     else break;
   }
   if(mid <= ans) {
     l = mid;
   }
   else {
     r = mid;
   }
 }
 std::cout << l << '\n';
 std::cout << l << '\n';
 for(int i=1;i<=n;i++) {
   if(l <= a[i]) {
     v.push_back(make_pair(t[i],i));
   }
 }
 sort(v.begin(),v.end());
 for(int i=0;i<l;i++) {
   std::cout << v[i].second << " ";
 }
 std::cout << '\n';
 cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
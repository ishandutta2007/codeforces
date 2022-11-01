#pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int maxn = 1e6+5;
const int mod = 1e9+7;
const ll INF = 2e15;
const double PI = acos(-1.0);
#define lson x << 1, l, mid
#define rson x << 1 | 1, mid + 1, r
const int lowbit(int x) { return x&-x; }
#define in freopen("in.txt","r",stdin)
std::map<int, int> mp;
std::vector<int> ans;
int main(int argc, char const *argv[]) {
   int n;
   std::cin >> n;
   int cnt = 0;
   for(int i=1;i<=9*n;i++) {
     int x = i;
     while(x%5==0) x/=5,cnt++;
     if(cnt==n)ans.push_back(i);
   }
   std::cout << (int)ans.size() << '\n';
   for(auto x : ans) {
     std::cout << x << " ";
   }
   std::cout << '\n';
  return 0;
}
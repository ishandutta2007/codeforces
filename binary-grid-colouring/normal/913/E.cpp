#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 256;
// ll n , L;
string ss[123][456];
int L[123][456];
string sss;
std::vector<pair<int,int> > v;
// ll a[maxn];
// int t[maxn];
// int res[maxn];
// int tmp[maxn];
// int ans,last;
struct node
{
  int v,m;
  string s;
  bool operator < (const node & a) const  {
    return ((int)s.size() == a.s.size() && a.s < s) || a.s.size() <(int) s.size();
  }
};
priority_queue<node>que;
void solve(int v,int m,string s) {
  /* code */
  if((L[m][v]==(int)s.size() && ss[m][v] > s) || (L[m][v] == 0) || ((int)s.size() < L[m][v]))
  {
     ss[m][v] = s;
    // std::cout << s << '\n';
     L[m][v] = (int)s.size();
     node b;
     b.v = v; b.m = m; b.s = s;
     que.push(b);
  }
}
void init()
{
  solve(0xf0, 0, "x");solve(0xcc, 0, "y");solve(0xaa, 0, "z");
}
int cas;
int main(int argc, char const *argv[]) {
 init();
 //std::cout << s << '\n';
 while(que.size()) {
   node b = que.top(); que.pop();
   string s;
   s =  b.s;
   int v = b.v, m = b.m;
   if(ss[m][v] != s) {
     continue;
   }
   if(m==0) {
     solve(255-v,0,"!"+s);
     solve(v,1,s);
     for(size_t i=0;i<maxn;i++) {
       if(L[1][i] != 0) {
         solve(v&i,1,ss[1][i]+"&"+s);
       }
     }
   }
   else if(m==1) {
     solve(v,2,s);
     for(size_t i=0;i<maxn;i++) {
       if(L[0][i]!=0) {
         solve(v&i,1,s+"&"+ss[0][i]);
       }
     }
     for (size_t i = 0; i < maxn; i++) {
       /* code */
       if (L[2][i]!=0) {
         /* code */
         solve(v|i,2,ss[2][i]+"|"+s);
       }
     }
   }
   else if(m>=2) {
     // if(L[2][i]=0) {
     //   solve(val|i,2,ss[2][i]+s+"|")
     // }
     solve(v,0,"("+s+")");
     for (size_t i = 0; i < maxn; i++) {
       /* code */
       if(L[1][i]!=0) {
         solve(v|i,2,s+"|"+ss[1][i]);
       }
     }
   }
 }
 int ans = 0;
 std::cin >> cas;
 while (cas--) {
   /* code */
   std::cin >> sss;
  // std::cout << sss.size() << '\n';
   ans = 0;
   for (size_t i = 0; i < 8; i++) {
     /* code */
     if(sss[i]=='1') {
       ans += (1<<i);
     }
   }
  // std::cout << "ans=" << ans << '\n';
   std::cout << ss[2][ans].c_str() << '\n';
 }
 cerr << "Time: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define min(...) minn(__VA_ARGS__)
#define max(...) maxx(__VA_ARGS__)
#define stringio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
char _;
typedef long long ll;
typedef pair<int,int> pii;
#define getchar_unlocked getchar
template<typename t>constexpr const t minn(const t x,const t y){return x<y?x:y;}
template<typename t,typename ...r>constexpr const t minn(const t x,const r ...xs){return minn(x,minn(xs...));}
template<typename t>constexpr const t maxx(const t x,const t y){return x>y?x:y;}
template<typename t,typename ...r>constexpr const t maxx(const t x,const r ...xs){return maxx(x,maxx(xs...));}
template <typename t> void scan (t& x) {do{while((x=getchar_unlocked())<'0'); for(x-='0'; '0'<=(_=getchar_unlocked()); x=(x<<3)+(x<<1)+_-'0');}while(0);}
template <typename t, typename ...r> void scan (t& x, r&... xs) {scan(x); scan(xs...);}
const int MAXN = 100005;
int cnt[4];
map<char,int> mp;
int main() {
  stringio();
  mp['s'] = 0, mp['p'] = 1, mp['m'] = 2;
	 string s1,s2,s3;
   cin >> s1 >> s2 >> s3;
   cnt[mp[s1[s1.length()-1]]]++;
   cnt[mp[s2[s2.length()-1]]]++;
   cnt[mp[s3[s3.length()-1]]]++;
   if (cnt[0] == 3 || cnt[1] == 3 || cnt[2] == 3) {
     int i[3];
     i[0] = stoi(s1.substr(0,s1.length()-1)), i[1] = stoi(s2.substr(0,s2.length()-1)), i[2] = stoi(s3.substr(0,s3.length()-1));
     sort (i,i+3);
     if ((i[1] - i[0] == 1 && i[2] - i[1] == 1) || (i[0] == i[1] && i[0] == i[2])) return !printf ("0\n");
     else if ((i[1] - i[0] == 1 || i[2] - i[1] == 1) || (i[0] == i[1] || i[1] == i[2]) || (i[2] - i[0] == 2 || (i[1]-i[0]==2) || (i[2]-i[1]==2))) return !printf ("1\n");
     else return !printf ("2\n");
   }
   else if (cnt[0] == 2 || cnt[1] == 2 || cnt[2] == 2) {
     int which = 0;
     if (cnt[0] == 2) which = 0;
     else if (cnt[1] == 2) which = 1;
     else which = 2;
     int i[2], ind = 0;
     if (mp[s1[s1.length()-1]] == which) i[ind++] = stoi(s1.substr(0,s1.length()-1));
     if (mp[s2[s2.length()-1]] == which) i[ind++] = stoi(s2.substr(0,s2.length()-1));
     if (mp[s3[s3.length()-1]] == which) i[ind++] = stoi(s3.substr(0,s3.length()-1));
     sort (i,i+2);
     if (i[1]-i[0] == 1 || i[1] == i[0] || i[1]-i[0]==2) return !printf ("1\n");
     else return !printf ("2\n");
   }
   else return !printf ("2\n");
   return 0;
}
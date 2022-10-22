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
struct three {int first,second,third;};
vector<three> l, g;
int main() {
    int n,a,b;
    scanf ("%d",&n);
    for (int x = 1; x <= n; x++) {
      scanf ("%d %d",&a,&b);
      if (a<b) l.push_back({a,b,x});
      else g.push_back({a,b,x});
    }
    sort(l.begin(),l.end(),[](three a, three b){return a.second > b.second;});
    sort(g.begin(),g.end(),[](three a, three b) {return a.second < b.second;});
    int ans1=0,ans2=0;
    three last = {0,INT_MAX,0};
    for (three p : l) {
      if (p.first < last.second) ans1++;
      else break;
      last = p;
    }
    last = {0,0,0};
    for (three p : g) {
      if (p.first > last.second) ans2++;
      else break;
      last = p;
    }
    if (ans1 > ans2) {
      printf ("%d\n",ans1);
        for (int x= 0; x < ans1; x++) printf ("%d ",l[x].third);
    }
    else {
      printf ("%d\n",ans2);
      for (int x=0;x<ans2;x++) printf ("%d ",g[x].third);
    }
    return !printf("\n");
}
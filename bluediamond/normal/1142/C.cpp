#include <bits/stdc++.h>

using namespace std;

#define int long long
bool home = 1;

const int N=(int) 1e5+7;

struct point{
  int x;
  int y;
};

int tr(point a,point b){
  return (a.x-b.x)*(a.y+b.y);
}

int tr(point a,point b,point c){
  return tr(a,b)+tr(b,c)+tr(c,a);
}

int n;
point a[N];

bool sm(point f,point s){
  if(f.x!=s.x)return f.x<s.x;
  return f.y<s.y;
}

int dis(point f){
  int dx=f.x-a[1].x;
  int dy=f.y-a[1].y;
  return dx*dx+dy*dy;
}

bool cmp(point f,point s){
  int k=tr(a[1],f,s);
  if(k==0){
    return dis(f)<dis(s);
  }
  return k<0;
}

signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0); cin.tie(0);
  }

  cin>>n;
  for (int i=1;i<=n;i++){
    cin>>a[i].x>>a[i].y;
    a[i].y-=a[i].x*a[i].x;
    if(sm(a[i],a[1]))swap(a[1],a[i]);
  }
  sort(a+2,a+n+1,cmp);

  vector<point> all;
  a[n+1]=a[1];
  for (int i=1;i<=n+1;i++){
    while(1){
      int k=(int)all.size();
      if(k>=2&&tr(all[k-2],all[k-1],a[i])>=0){
        k--;
        all.pop_back();
      }else{
        break;
      }
    }
    all.push_back(a[i]);
  }

  int sol=0;
  for (int i=0;i+1<(int)all.size();i++){
    if(all[i].x<all[i+1].x){
      sol++;
    }
  }
  cout<<sol<<"\n";

  return 0;
}
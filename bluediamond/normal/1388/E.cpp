#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int N=(int) 2e3+7;
ld sol=1e18;
int n;
ld l[N],r[N],h[N];
vector<int> o;

pair<ld,ld> get(int i,ld e) {
  return {l[i]+e*h[i],r[i]+e*h[i]};
}

void print(pair<ld,ld> it){
  cout<<it.first<<" "<<it.second<<"   ";
}

ld to(ld p1, ld h1, ld p2, ld h2) {
  /// p1+e*h1=p2+e*h2
  /// p1-p2=e*(h2-h1)
  return (p1-p2)/(h2-h1);
}

ld f(ld e) {
  vector<pair<ld, ld>> segments;
  pair<ld,ld> cr=get(o[0],e);
  segments.push_back(cr);
  for (int i=1;i<n;i++) {
    pair<ld,ld> it=get(o[i],e);
    cr.first=min(cr.first,it.first);
    cr.second=max(cr.second,it.second);
    segments.push_back(it);

  }
  sort(segments.begin(),segments.end());
  for (int i=1;i<n;i++) {
    if (segments[i-1].second>segments[i].first) return -(ld) 1e9;
  }

  return cr.second-cr.first;
}

void upd(ld e) {
  vector<pair<ld, ld>> segments;
  pair<ld,ld> cr=get(o[0],e);
  segments.push_back(cr);
  for (int i=1;i<n;i++) {
    pair<ld,ld> it=get(o[i],e);
    cr.first=min(cr.first,it.first);
    cr.second=max(cr.second,it.second);
    if (cr.second-cr.first>=sol) return;
    segments.push_back(it);

  }
  sort(segments.begin(),segments.end());
  for (int i=1;i<n;i++) {
    if (segments[i-1].second>segments[i].first) return;
  }
  sol=cr.second-cr.first;
}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

vector<ld> all;

void te(int i) {
  int l=i-5,r=i+5;
  for (int j=l;j<=r;j++) {
    if(0<=j && j<(int) all.size()) upd(all[j]);
  }
}

signed main() {
 ios::sync_with_stdio(0); cin.tie(0);
  cin>>n;
  time_t bg=clock();
  for (int i=1;i<=n;i++) cin>>l[i]>>r[i]>>h[i];
  for (int i=1;i<=n;i++) o.push_back(i);

  for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) if (h[i]!=h[j]) all.push_back(to(r[i],h[i],l[j],h[j]));
  all.push_back(0);
  sort(all.begin(),all.end());
  int l=0,r=(int) all.size()-1;
  te(0);
  te((int) all.size()-1);
  int last=-1;
  while (l<=r) {
    int m=(l+r)/2;
    ld val=f(all[m]);
    if (val!=-(ld) 1e9 && (m==0 || (m>=1 && f(all[m-1])>=val))) {
      last=m;
      l=m+1;
    } else r=m-1;
  }
  te(last);
  l=last+1,r=(int) all.size()-1;
  while(l<=r){
    int m=(l+r)/2;
    ld val=f(all[m]);
    if (val==-(ld) 1e9) {
      last=m;
      l=m+1;
    }  else r=m-1;
  }
    te(last);
  shuffle(all.begin(),all.end(),rnd);

  int pos=0;
  while (pos<(int) all.size()) {
    time_t nd=clock();
    double dif=(double) (nd-bg)/CLOCKS_PER_SEC;
    if (dif>3.9) break;
    upd(all[pos]);
    pos++;
  }
  cout<<fixed<<setprecision(6)<<sol<<"\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld eps=1e-14;

struct point {
  ld x;
  ld y;
  int i;
};

ld f(point a, point b) {
  return (a.x - b.x) * (a.y + b.y);
}

ld f(point a, point b, point c) {
  return f(a, b) + f(b, c) + f(c, a);
}

int g(point a, point b, point c) {
  ld v = f(a, b, c);
  if (v == 0) {
    return 0;
  }
  if (v > 0) {
    return +1;
  } else {
    return -1;
  }
}

point min(point a, point b) {
  if (a.x < b.x) return a;

  if (b.x < a.x) return b;
  if (a.y < b.y) {
    return a;
  } else {
    return b;
  }
}

point min2(point a,point b){
  if (a.y < b.y) return a;

  if (b.y < a.y) return b;
  if (a.x < b.x) {
    return a;
  } else {
    return b;
  }
}

bool operator == (point a, point b) {
  return a.x == b.x && a.y == b.y;
}

const int N = (int)2e5 + 7;
vector<int>cn[N];
int n;
int top;
point p[N];
point stk[N];

ld dis(point a,point b){
  ld dx=a.x-b.x;
  ld dy=a.y-b.y;
  return dx*dx+dy*dy;
}

bool operator < (point a, point b) {
  int gg=g(p[1],a,b);
 /// if(gg==0)return dis(p[1],a)-dis(p[1],b)<eps;
  return gg>0;
}
int main() {
  ios::sync_with_stdio(0);cin.tie(0);
  //freopen("input","r",stdin);

  cin >> n;
 // bool ok=(n==196296);
  map<pair<int,int>,vector<int>>ul;
  for (int i = 1; i <= n; i++) {int tx,ty;
    cin>>tx>>ty;
    ul[make_pair(tx,ty)].push_back(i);
  }
  int kol=0;
  for (auto &it:ul) {
    kol++;
    for (auto &j:it.second){
      cn[kol].push_back(j);
    }
    p[kol].x=(ld)1/(ld)it.first.first;
    p[kol].y=(ld)1/(ld)it.first.second;
    p[kol].i=kol;

  }
  n=kol;
  for (int i = 2; i <= n; i++) {
    if (p[i] == min(p[i], p[1])) {
      swap(p[1], p[i]);
    }
  }
  sort(p + 2, p + n + 1);

  /**
  for (int i=1;i<=n;i++){
    cout<<p[i].x<<" "<<p[i].y<<"\n";
  }**/

///if(ok)return 0;

  p[n + 1] = p[1];
  for (int i = 1; i <= n + 1; i++) {
    while (top >= 2 && g(stk[top - 1], stk[top], p[i]) < 0) {
      top--;
    }
    stk[++top] = p[i];
  }
  top--;


  point m1=stk[1],m2=stk[1];


  for (int i=2;i<=top;i++){
    m1=min(m1,stk[i]);
    m2=min2(m2,stk[i]);
  }


  /**
  for (int i=1;i<=top;i++){
    cout<<stk[i].x<<" "<<stk[i].y<< " P"<<cn[stk[i].i][0]<<"\n";
  }
  cout<<"\n";
  cout<<m1.x<<" "<<m1.y<<" M1\n";
  cout<<m2.x<<" "<<m2.y<<" M2\n";**/

 /// return 0;


  set<int>sl;
   if(m1.x==m2.x&&m1.y==m2.y){
   for (int i = 1; i <= top; i++) {
    if(stk[i]==m1){
      ///cout<<"uu: " << fixed<<setprecision(6)<<f(stk[i],m1,m2)<< " " << g(stk[i],m1,m2)<<"\n";
      for (auto &j:cn[stk[i].i])
      sl.insert(j);
    }
    //cout << fixed << setprecision(12) << stk[i].x << " " << stk[i].y<<" "<<stk[i].i << "\n";
  }
 }else
  //cout << top << "\n";
  for (int i = 1; i <= top; i++) {
    if(g(stk[i],m1,m2) <= 0){
      ///cout<<"uu: " << fixed<<setprecision(6)<<f(stk[i],m1,m2)<< " " << g(stk[i],m1,m2)<<"\n";
      for (auto &j:cn[stk[i].i])
      sl.insert(j);
    }
    //cout << fixed << setprecision(12) << stk[i].x << " " << stk[i].y<<" "<<stk[i].i << "\n";
  }
  for (auto &i:sl){
    cout<<i << " ";
  }
  cout<<"\n";
}
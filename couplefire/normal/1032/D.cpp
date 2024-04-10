#include <bits/stdc++.h>
using namespace std;
long double a, b, c;
pair<long double, long double> one;
pair<long double, long double> two;

long double dis(pair<long double, long double> a, pair<long double, long double> b){
  return sqrt(pow((a.first-b.first),2)+pow(a.second-b.second, 2));
}

long double mat(pair<long double, long double> a, pair<long double, long double> b){
  return abs(a.first-b.first)+abs(a.second-b.second);
}

vector<pair<long double, long double>> inter(){
  vector<pair<long double, long double>> v;
  set<pair<long double, long double>> st;
  long double i1, i2, i3, i4;
  i1 = (-b*one.second-c)/a;
  i2 = (-a*two.first-c)/b;
  i3 = (-b*two.second-c)/a;
  i4 = (-a*one.first-c)/b;
  if((i1 <= one.first && i1 >= two.first) || (i1 >= one.first && i1 <= two.first)){
    if(!st.count({i1, one.second})){
      v.push_back({i1, one.second});
      st.insert({i1, one.second});
    }
  }
  if((i3 <= one.first && i3 >= two.first) || (i3 >= one.first && i3 <= two.first)){
    if(!st.count({i3, two.second})){
      v.push_back({i3, two.second});
      st.insert({i3, two.second});
    }
  }
  if((i2 <= one.second && i2 >= two.second) || (i2 >= one.second && i2 <= two.second)){
    if(!st.count({two.first, i2})){
      v.push_back({two.first, i2});
      st.insert({two.first, i2});
    }
  }
  if((i4 <= one.second && i4 >= two.second) || (i4 >= one.second && i4 <= two.second)){
    if(!st.count({one.first, i4})){
      v.push_back({one.first, i4});
      st.insert({one.first, i4});
    }
  }
  return v;
}

int main() {
  cout << setprecision(8);
  cin >> a >> b >> c;
  cin >> one.first >> one.second >> two.first >> two.second;
  long double normaldis = abs(one.first-two.first)+abs(one.second-two.second);
  if(a == 0 || b == 0){
    cout << normaldis << endl;
    return 0;
  }
  vector<pair<long double, long double>> vv = inter();
  long double ans;
  if(vv.size() != 2) ans = normaldis;
  else ans = min(mat(one, vv[0])+mat(two, vv[1]), mat(one, vv[1])+mat(two, vv[0]))+dis(vv[0], vv[1]);
  cout << min(ans, normaldis) << endl;
}
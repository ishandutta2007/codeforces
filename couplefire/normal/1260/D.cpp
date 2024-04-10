#include <bits/stdc++.h>
using namespace std;

struct e{
  int l, r, d;
  e(){}
  e(int ll, int rr, int dd){l = ll, r = rr, d = dd;}
  bool operator < (const e &b) const{
      return l < b.l;
  }
};
vector<e> eve;

int m, n, k, t;
vector<int> arr;

bool check(int num){
    int llo = arr[m-num];
    vector<e> active;
    for(auto i : eve){
        if(i.d > llo) active.push_back(i);
    }
    int sum = n+1;
    int be = 0;
    priority_queue<int> pq;
    for(auto i : active){
        if(pq.empty()){
            pq.push(i.r);
            be = i.l;
            continue;
        }
        if(i.l > pq.top()){
            sum += (pq.top()-be+1)*2;
            pq = priority_queue<int>();
            be = i.l;
            pq.push(i.r);
        }
        else pq.push(i.r);
    }
    if(!pq.empty()) sum += 2*(pq.top()-be+1);
    //cout << num << " " << sum << endl;
    return sum > t;
}

int main() {
  //freopen("a.in", "r", stdin);
  cin >> m >> n >> k >> t;
  arr.resize(m);
  for(int i = 0; i<m; i++) cin >> arr[i];
  sort(arr.begin(), arr.end());
  eve.resize(k);
  for(int i = 0; i<k; i++){
    int a, b, c; cin >> a >> b >> c;
    eve[i] = {a, b, c};
  }
  int lo = 0;
  int hi = m;
  sort(eve.begin(), eve.end());
  while(lo < hi){
    int mid = lo+(hi-lo+1)/2;
    if(check(mid)) hi = mid-1;
    else lo = mid;
  }
  cout << lo << endl;
}
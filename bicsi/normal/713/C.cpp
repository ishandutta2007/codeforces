#include <bits/stdc++.h>
 
using namespace std;
 
struct MedianHeap {
  priority_queue<int> lo, hi;
  void Add(int elem) {
    if (lo.empty() || elem <= lo.top()) {
      lo.push(elem);
      if (lo.size() > hi.size() + 1) {
        hi.push(-lo.top());
        lo.pop();
      }
    } else {
      hi.push(-elem);
      if (hi.size() >= lo.size() + 1) {
        lo.push(-hi.top());
        hi.pop();
      }
    }
  }
  int Get() { return lo.top(); }
};
 
int main() {
 
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) 
    cin >> v[i];
  
  vector<MedianHeap> heaps;
 
  for (int i = 0; i < n; ++i) {
    int now = v[i] - i;
    heaps.emplace_back();
    heaps.back().Add(now);
    while (heaps.size() > 1) {
      auto& small = *(heaps.end() - 1);
      auto& big = *(heaps.end() - 2);
      if (small.Get() > big.Get()) break;
      else {
        if (small.lo.size() + small.hi.size() > big.lo.size() + big.hi.size()) {
          swap(small, big);
        }
        while (small.lo.size()) {
          big.Add(small.lo.top());
          small.lo.pop();
        }
        while (small.hi.size()) {
          big.Add(-small.hi.top());
          small.hi.pop();
        }
        heaps.pop_back();
      }
    }  
  }
 
  long long total = 0;
  for (auto& heap : heaps) {
    int target = heap.Get();
    while (heap.lo.size()) {
      total += target - heap.lo.top();
      heap.lo.pop();
    }
    while (heap.hi.size()) {
      total += -heap.hi.top() - target;
      heap.hi.pop();  
    }
  }
  cout << total << endl;
 
  return 0;
}
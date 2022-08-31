#include <bits/stdc++.h>

using namespace std;

struct Medianer{//running median
  priority_queue<int> low;
  priority_queue<int, vector<int>, greater<int> > high;
  Medianer(){}
  int getMedian(){
    return low.top();
  }
  void insert(int a){
    if(low.empty()) low.push(a);
    else if(a > low.top()){
      high.push(a);
    } else low.push(a);

    while(low.size()> high.size()){//balance to equal size
      high.push(low.top());
      low.pop();
    }
    while(low.size() < high.size()){
      low.push(high.top());
      high.pop();
    }
  }
  size_t size(){
    return low.size()+high.size();
  }
};
Medianer * merge(Medianer *a, Medianer *b){
  if(a->size() < b->size())swap(a, b);
  while(!b->low.empty()){
    a->insert(b->low.top());
    b->low.pop();
  }
  while(!b->high.empty()){
    a->insert(b->high.top());
    b->high.pop();
  }
  delete b;
  return a;
}

int main()
{
  int N;
  cin >> N;
  vector<int> data(N, 0);
  copy_n(istream_iterator<int>(cin), N, data.begin());
  vector<Medianer *> meds;
  for(int i=0;i<N;++i){
      //cerr << "at: " << i << "\n";
      Medianer * cur = new Medianer();
      cur->insert(data[i]);
      while(!meds.empty() && cur->getMedian() < meds.back()->getMedian()){
        cur=merge(meds.back(), cur);
        meds.pop_back();
        //cerr << "merge -> " << cur->getMedian() << "\n";
      }
      meds.push_back(cur);
  }
  unsigned long long ret = 0;
  for(int i=0, j=0;i<(int)meds.size();++i){
    for(int k=0;k<(int)meds[i]->size();++k, ++j){
      ret+=abs(data[j]-meds[i]->getMedian());
    }
    delete meds[i];
  }
  cout << ret;


  return 0;
}
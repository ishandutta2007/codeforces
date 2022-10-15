#include <bits/stdc++.h>

using namespace std;

int get(vector<int> a, vector<int> b) {
  assert(!a.empty());
  assert(!b.empty());
  cout<<"? "<<(int)a.size()<<" "<<(int)b.size()<<endl;
  for (auto &x:a) cout<<x<<" ";cout<<endl;
  for (auto &x:b) cout<<x<<" ";cout<<endl;
  int sol;
  cin>>sol;
  return sol;
}

void print(vector<int> a) {
  cout << "\t\t\t\t\t ---> ";
  for (auto &x : a) {
    cout << x << " ";
  }
  cout << endl;
}

int main() {
  int tests;
  cin>>tests;
  for (int tc=1;tc<=tests;tc++) {
    int n;
    bool found=0;
    cin>>n;
    vector<int> pref={1};
    for (int sc=2;sc<=n;sc++) {
      if (get(pref,{sc})==0){
        pref.push_back(sc);
        continue;
      }
      /// 0 0 0 0 0 !=0 !=0 !=0 !=0
      int low=1,high=sc-1,fi=-1;
      while(low<=high) {
        int mid=(low+high)/2;
        vector<int> lol;
        for(int i=1;i<=mid;i++)lol.push_back(i);
        if (get(lol,{sc})!=0){
          fi=mid;
          high=mid-1;
        }else{
          low=mid+1;
        }
      }
      assert(fi!=-1);
      vector<int> sol;
    //  cout<<"\t\t\t\t fi = "<<fi<<endl;
      for (int i=1;i<sc;i++) if(i!=fi) sol.push_back(i);
    //  print(sol);
      for (int i=sc+1;i<=n;i++) if(get({sc},{i})==0) sol.push_back(i);
    //  print(sol);
      cout<<"! ";
      cout<<(int)sol.size()<<" ";
      for (auto &i:sol){
        cout<<i<<" ";
      }
      cout<<endl;
      found=1;
      break;
    }
    assert(found);
  }

}
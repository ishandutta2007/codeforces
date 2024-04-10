#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
mt19937 rng((long long) (new char));

int total_t;
int n;

int ask(string s) {
  cout<<s<<endl;
  int ret;
  cin>>ret;
  if(ret==n){
    exit(0);
  }
  if(ret==-1){
    exit(0);
  }
  return ret;
}

int get_f(vector<int> inds) {
  string sol(n,'T');
  for(auto&i:inds){
    sol[i]='F';
  }
  return ((int)inds.size()+ask(sol)-total_t)/2;
}

const int WANTED_SIZE=10;
int cnt_bits[1<<WANTED_SIZE];
string print;

void solve(vector<int> inds){
  int dim=(int)inds.size();
  int cnt_f=get_f(inds);
  vector<int> possible;
  for(int mask=0;mask<(1<<dim);mask++) {
    if(cnt_bits[mask]==cnt_f){
      possible.push_back(mask);
    }
  }
  while((int)possible.size()>1){
    vector<pair<ld,int>> options;
    for (int m=0;m<(1<<dim);m++) {
      vector<double> prob(dim+1,0);
      for(auto &mask:possible){
        prob[cnt_bits[mask&m]]++;
      }
      for(auto &x:prob){
        x/=(ld)(possible.size());
      }
      ld entropy=0;
      for(auto&x:prob){
        if(x){
          entropy+=-1*x*log2(x);
        }
      }
      options.push_back({entropy, m});
    }
    assert(!options.empty());
    sort(options.rbegin(),options.rend());
    int m=options[0].second;
    vector<int> ia;
    for (int i=0;i<dim;i++){
      if(m&(1<<i)){
        ia.push_back(inds[i]);
      }
    }
    int ret=get_f(ia);
    vector<int> np;
    for (auto &mask:possible){
      if(cnt_bits[mask&m]==ret){
        np.push_back(mask);
      }
    }
    possible=np;
  }
  assert((int)possible.size()==1);
  int mask=possible[0];
  for (int i=0;i<dim;i++){
    if(mask&(1<<i)) {
      print[inds[i]]='F';
    }else{
      print[inds[i]]='T';
    }
  }
}

int main() {
  for(int i=0;i<(1<<WANTED_SIZE);i++){
    cnt_bits[i]=__builtin_popcount(i);
  }
  cin>>n;
  for (int i=0;i<n;i++)print.push_back('-');
  total_t=ask(string(n,'T'));

  vector<int> inds(n);
  iota(inds.begin(),inds.end(), 0);
  shuffle(inds.begin(),inds.end(), rng);

  for (int st=0;st<n;st+=WANTED_SIZE){
    int dr=min(n-1,st+WANTED_SIZE-1);
    vector<int> send;
    for(int j=st;j<=dr;j++){
      send.push_back(inds[j]);
    }
    solve(send);
  }
  cout<<print<<endl;
}
/**
aflu cnt_t, cnt_f

answer = cnt_f(set) + cnt_t(outside of set)
answer = cnt_f(set) + cnt_t - cnt_t(set)

cnt_f(set) - cnt_t(set) = answer - cnt_t
cnt_t(set) + cnt_f(set) = set.size()
cnt_f(set) = (set.size() + answer - cnt_t) / 2

cnt_f(set) = ?



cnt_t(set) + cnt_f(set) = set.size()
cnt_t + cnt_f = n

stiu cnt_t si cnt_f

**/
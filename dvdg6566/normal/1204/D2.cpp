#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vpi;
typedef pair<int,pi> pii;
#define pb emplace_back
#define mp make_pair
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define ALL(X) X.begin(),X.end()
#define SZ(X) (int)X.size()
#define MAXN 1000100
#define INF 1e9

string S;
int offset[MAXN];
vector<pi> V;

int main(){
  cin>>S;
  int lst = -1;
  int li = -1;
  if (S[0]=='1')V.pb(0,0);
  for (int i=0;i<SZ(S);++i){
    int ind = S[i]-'0';
    if(ind == lst)continue;
    if (lst != -1)V.pb(lst, i-li);
    lst = ind;
    li = i;
  }
  V.pb(lst,SZ(S)-li);
  // for (auto i : V)cout<<i.f<<' '<<i.s<<'\n';
  if (SZ(V) == 0)return 0;
  bool flag = 0;
  if (V.back().f != 0){
    flag = 1;V.pb(mp(0,0));
  }

  int prevlen = 0;
  int zeroes = 0;
  vi ans;

  for (int ind = SZ(V)-2;ind>=1;ind -= 2){
    zeroes += V[ind+1].s;
    int t = V[ind].s;
    int minval = V[ind+1].s;
    // cout<<"Value between "<<minval<<' '<<t<<'\n';
    // cout<<"Zeroes "<<zeroes<<'\n';
    if (zeroes >= t){
      // Must keep entire thing
      zeroes -= t;
      ans.pb(t);
      // cout<<"Must keepi "<<t<<'\n';
      continue;
    }
    int keep = max(minval, zeroes);
    // cout<< "Ok, keep "<<keep<<'\n';
    zeroes -= keep;
    if(zeroes>0)zeroes += t;
    ans.pb(keep);
    // cout<<"Zeroes value "<<zeroes<<'\n';
  }
  
  if(flag)V.pop_back();

  for (auto i : V){
    if (i.f==0){
      for (int j=0;j<i.s;++j)cout<<'0';
    }else{
      for (int j=ans.back();j<i.s;++j)cout<<'0';
      for (int j=0;j<ans.back();++j)cout<<'1';
      ans.pop_back();
    }
  }
}
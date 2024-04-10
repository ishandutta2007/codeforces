#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <deque>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 2001001001
#define MOD 1000000007

vector<pair<int,int>>v; //start, dur
int N;
int S[201],D[201];
int ans[201];

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  cin>>N;
  for (int i=0;i<N;i++){
    cin>>S[i]>>D[i];
    sort(v.begin(),v.end());
    //first one
    bool flag=true;
    for (int j=0;j<(int)v.size();j++)
      if (!(v[j].first+v[j].second<S[i] || v[j].first>=S[i]+D[i]))
	flag=false;
    if (flag){
      v.push_back({S[i],D[i]});
      ans[i]=S[i];
      continue;
    }
    //second one
    if (D[i]<v[0].first){
      v.push_back({1,D[i]});
      ans[i]=1;
      continue;
    }
    for (int j=0;j+1<(int)v.size();j++)
      if (v[j+1].first-(v[j].first+v[j].second)>=D[i]){
	v.push_back({v[j].first+v[j].second,D[i]});
	ans[i]=v[j].first+v[j].second;
	break;
      }
    if ((int)v.size()!=i+1){
      ans[i]=v[(int)v.size()-1].first+v[(int)v.size()-1].second;
      v.push_back({ans[i],D[i]});
    }
  }
  for (int i=0;i<N;i++)
    cout<<ans[i]<<' '<<ans[i]+D[i]-1<<endl;
  return 0;
}
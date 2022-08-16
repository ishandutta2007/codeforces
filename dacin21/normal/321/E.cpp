
#include <bits/stdc++.h>

#if 0
#define getchar _getchar_nolock

#endif // LOCAL

using namespace std;

void readInt(int &x){
  x=0;
  int a=getchar();
  while(a>'9'||a<'0') a = getchar();
  while(a<='9'&&a>='0') x=x*10+a-'0', a = getchar();
}

int main()//http://codeforces.com/contest/321/problem/E
{
  int N, K;
  readInt(N);
  readInt(K);
  vector<vector<int> > data(N+1, vector<int> (N+1, 0));
  char c;
  for(int i=1;i<=N;++i){
    for(int j=1;j<=N;++j){
        c=getchar();
        while(c<'0'||c>'9') c = getchar();
        data[i][j] +=c - '0' + data[i-1][j]+data[i][j-1] - data[i-1][j-1];
    }
  }
  auto cost = [&] (int a, int b) {return data[b+1][b+1] - 2*data[b+1][a] + data[a][a];};
  vector<int> oldDP(N, 0x3FFFFFFF), DP(N, 0x3FFFFFFF);
  for(int i=0;i<N;++i){
    DP[i] = cost(0, i);
  }
  pair<int, int> curRange, optRange;
  for(int i=1;i<K;++i){
      //cerr << i << " splits: \n";
      oldDP.swap(DP);
      DP = vector<int> (N, 0x3FFFFFFF);
      stack<pair<pair<int, int>, pair<int, int> > > s; //rangeL, RangeR, OptL, OptR
      s.emplace(make_pair(1, N-1), make_pair(0, N-2));
      while(!s.empty()){
        tie(curRange, optRange) = s.top();
        s.pop();
        if(curRange.first > curRange.second) continue;
        int med = (curRange.first+curRange.second)/2;
        int curOpt = -1;
        for(int j=optRange.first; j<=optRange.second;++j){
          if(DP[med] > oldDP[j] + cost(j+1, med)){
            DP[med] = oldDP[j] + cost(j+1, med);
            curOpt = j;
          }
        }
        //cerr << "DP: " << med << ": " << DP[med] << " at: " << curOpt <<"\n";
        if(curRange.first!=curRange.second){
          s.emplace(make_pair(curRange.first, med-1), make_pair(optRange.first, curOpt));
          s.emplace(make_pair(med+1, curRange.second), make_pair(curOpt, optRange.second));
        }
      }
  }
  cout << DP[N-1]/2;


  return 0;
}
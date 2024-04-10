#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=1500+7;
int n,m,a[N][N],b[N][N],ord[N];
int cnt_problems[N];
bool lipit[N];

int main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0); cout.tie();
#endif /// ONLINE_JUDGE

#ifndef ONLINE_JUDGE
  freopen ("___input___.txt", "r", stdin);
#endif // ONLINE_JUDGE

  cin>>n>>m;

  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      cin>>a[i][j];
    }
  }

  for (int i=1;i<=n;i++) {
    for (int j=1;j<=m;j++) {
      cin>>b[i][j];
    }
  }

  for (int i=1;i<n;i++) {
    lipit[i]=1;
  }

  for (int j=1;j<=m;j++) {
    for (int i=1;i<n;i++) {
      if(b[i][j]>b[i+1][j]){
        cnt_problems[j]++;
      }
    }
  }

  vector<int> no_problems;
  for (int j=1;j<=m;j++) {
    if(cnt_problems[j]==0){
      no_problems.push_back(j);
    }
  }

  for (int iter=0;iter<(int)no_problems.size();iter++) {
    int col=no_problems[iter];
    for (int i=1;i<n;i++){
      if (lipit[i]&&b[i][col]!=b[i+1][col]){
        lipit[i]=0;
        for (int j=1;j<=m;j++) {
          if(b[i][j]>b[i+1][j]){
            cnt_problems[j]--;
            if(cnt_problems[j]==0){
              no_problems.push_back(j);
            }
          }
        }
      }
    }
  }

  reverse(no_problems.begin(),no_problems.end());

  for (int i=1;i<=n;i++) {
    ord[i]=i;
  }
  for (auto &col:no_problems){
    stable_sort(ord+1,ord+n+1,[&](int i,int j) {
         return a[i][col]<a[j][col];
         });
  }
  for(int i=1;i<=n;i++){
    for(int j=1;j<=m;j++){
      if(a[ord[i]][j]!=b[i][j]){
        cout<<"-1\n";
        exit(0);
      }
    }
  }
  cout<<(int)no_problems.size()<<"\n";
  for (auto &j:no_problems){
    cout<<j<<" ";
  }
  cout<<"\n";
  exit(0);
}
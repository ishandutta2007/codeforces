#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
#include <stdio.h>
using namespace std;
vector<int> diagA[1000];
vector<int> diagB[1000];
int main(){
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        int a;
        cin>>a;
        diagA[i+j].push_back(a);
      }
    }
    for(int i=0;i<N;i++){
      for(int j=0;j<M;j++){
        int a;
        cin>>a;
        diagB[i+j].push_back(a);
      }
    }
    for(int i=0;i<1000;i++){
      sort(diagA[i].begin(),diagA[i].end());
      sort(diagB[i].begin(),diagB[i].end());
    }
    for(int i=0;i<1000;i++){
      for(int j=0;j<diagA[i].size();j++){
        if(diagA[i][j]!=diagB[i][j]){
          cout<<"NO";
          return 0;
        }
      }
    }
    cout<<"YES";
    return 0;
}
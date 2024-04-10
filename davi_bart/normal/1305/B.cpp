#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> p,s;
vector<vector<int> > sol;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string a;
    cin>>a;
    int N=a.size();
    p.resize(N);
    s.resize(N);
    while(1){
      fill(p.begin(),p.end(),0);
      fill(s.begin(),s.end(),0);
      for(int i=0;i<N;i++){
        if(a[i]=='(')p[i]++;
        if(i<N-1)p[i+1]=p[i];
      }
      for(int i=N-1;i>=0;i--){
        if(a[i]==')')s[i]++;
        if(i>0)s[i-1]=s[i];
      }
      int ma=-1,pos;
      for(int i=0;i<N-1;i++){
        if(min(p[i],s[i+1])>ma){
          ma=min(p[i],s[i+1]);
          pos=i;
        }
      }
      if(ma==0)break;
      int k=ma;
      sol.push_back(vector<int>());
      for(int i=0;i<=pos;i++){
        if(a[i]=='(' && k>0){
            k--;
            a[i]='a';
            sol.back().push_back(i+1);
        }
      }
      for(int i=N-1;i>=0;i--){
        if(a[i]==')' && ma>0){
            a[i]='a';
            ma--;
            sol.back().push_back(i+1);
        }
      }
    }
    cout<<sol.size()<<'\n';
    for(int i=0;i<sol.size();i++){
      cout<<sol[i].size()<<'\n';
      sort(sol[i].begin(),sol[i].end());
      for(int j=0;j<sol[i].size();j++)cout<<sol[i][j]<<" ";
      cout<<'\n';
    }
    return 0;
}
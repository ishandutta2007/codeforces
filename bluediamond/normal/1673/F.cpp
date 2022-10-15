#include <bits/stdc++.h>


using namespace std;

const int N=32+7;
int xoru[N][N],gary[N];


signed main() {

  {
    {
      int cur=1;
      gary[0]=0;
      while(cur<32){
        for(int i=0;i<cur;i++){
          gary[i+cur]=cur+gary[cur-1-i];
        }
        cur*=2;
      }
    }
    {
      for(int i=0;i<32;i++){
        for(int j=0;j<32;j++){
          int bitz=0;
          for(int k=0;k<5;k++){
            if(gary[i]&(1<<k)) bitz+=(1<<(2*k));
            if(gary[j]&(1<<k)) bitz+=(1<<(2*k+1));
          }
          xoru[i][j]=bitz;
        }
      }
    }
  }

  int n,k;
  cin>>n>>k;
  for (int i=0;i<n;i++){
    for(int j=0;j<n-1;j++) cout<<(xoru[i][j]^xoru[i][j+1])<<" ";
    cout<<endl;
  }
  for (int i=0;i+1<n;i++){
    for(int j=0;j<n;j++) cout<<(xoru[i][j]^xoru[i+1][j])<<" ";
    cout<<endl;
  }
  int r=0,c=0;
  for (int ik=1;ik<=k;ik++){
    int xo;
    cin>>xo;
    int rs=-1,cs=-1;
    for (int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if((xoru[i][j]^xoru[r][c])==xo){
          assert(rs==-1);
          assert(cs==-1);
          rs=i;
          cs=j;
        }
      }
    }
    assert(0<=rs&&rs<n);
    assert(0<=cs&&cs<n);
    r=rs;
    c=cs;
    cout<<rs+1<<" "<<cs+1<<endl;
  }
}
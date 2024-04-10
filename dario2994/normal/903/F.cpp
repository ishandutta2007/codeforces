#include <bits/stdc++.h>
using namespace std;
int d[1100][1<<12],m[1100][4],a[5];
vector<int>s[3]={{1,2,4,8},{51,102,204},{-2185,-274}};

int main() {
 int N;
 cin >> N;
 for(int i=0;i<4;i++)cin>>a[i];
 for(int r=0;r<4;r++)for(int c=0;c<N;c++){
  char x;
  cin>>x;
  m[c][r]=x=='*';
 }
 for(int i=N+5;i>=0;i--) {
  for(int b=0; b<1<<12;b++) {
   if(b%(1<<4)==0) {
    int c=b/16;
    for(int r=0;r<4;r++)c+=(1<<(8+r))*m[i][r];
    d[i][b]=d[i+1][c];
    continue;
   }
   d[i][b]=d[i+1][0]+a[3];
   for(int l=0;l<3;l++)for(int S:s[l])d[i][b]=min(d[i][b],a[l]+d[i][b&(~S)]);
  }
 }
 cout<<d[0][0];
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char s[4][123];
int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  if(n&1)
  {
    for(int i=1,j=0;i<n;i+=2,j++) {
      if(j&1) {
        s[0][i] = s[0][i+1] = 'b';
        s[1][i] = s[1][i+1] = 'c';
      }
      else
      {
        s[0][i] = s[0][i+1] = 'd';
        s[1][i] = s[1][i+1] = 'e';
      }
    }
    for(int i=0,j=0;i<n;i+=2,j++) {
      if(j&1)
      {
        s[2][i] = s[2][i+1] = 'f';
        s[3][i] = s[3][i+1] = 'g';
      }
      else
      {
        s[2][i] = s[2][i+1] = 'h';
        s[3][i] = s[3][i+1] = 'i';
      }
    }
    s[0][0] = s[1][0] = 'a';
    s[2][n-1] = s[3][n-1] = 'z';
  }
  else
  {
      for(int i=1,j=0;i<n;i+=2,j++)
      {
          if(j&1){
              s[1][i]=s[1][i+1]='b';
              s[2][i]=s[2][i+1]='c';
          }
          else {
            s[1][i]=s[1][i+1]='d';
            s[2][i]=s[2][i+1]='e';
          }
        }
      for(int i=0,j=0;i<n;i+=2,j++)
      {
          if(j&1) {
            s[0][i]=s[0][i+1]='f';
            s[3][i]=s[3][i+1]='g';
          }
          else {
            s[0][i]=s[0][i+1]='h';
            s[3][i]=s[3][i+1]='i';
          }

      }
      s[2][0]=s[1][0]='a';
      s[2][n-1]=s[1][n-1]='z';
  }
  s[0][n]=s[1][n]=0;
  s[2][n]=s[3][n]=0;
  for(int i=0;i<4;i++) {
    std::cout << s[i] << '\n';
  }
  return 0;
}
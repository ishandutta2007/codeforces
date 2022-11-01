#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[21];
int main(int argc, char const *argv[]) {
  int r1,r2;
  int c1,c2,d1,d2;
  std::cin >> r1 >> r2;
  std::cin >> c1 >> c2;
  std::cin >> d1 >> d2;
  for(int i=1;i<=9;i++){
    for(int j=1;j<=9;j++){
      for(int k=1;k<=9;k++){
        for(int u=1;u<=9;u++){
          if(i+j==r1 && k+u==r2 && i+k==c1 && j+u==c2 && i+u==d1 && k+j==d2
             && i!=j && i!=k && i!=u && j!=k && j!=u && k!=u){
               printf("%d %d\n%d %d\n",i,j,k,u);
               return 0;
             }
        }
      }
    }    
  }
 std::cout << "-1" << '\n';
  return 0;
}
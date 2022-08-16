#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

int main()
{
  /*ifstream is("in.txt");
  cin.rdbuf(is.rdbuf());*/

  int yMax, xMax;
  cin >> yMax >> xMax;
  vector<vector<int> > image(yMax, vector<int>(xMax, 0));

  char tmp;
  for(int i=0;i<yMax;++i){
    for(int j=0;j<xMax;++j){
      cin >> tmp;
      if(tmp=='W'){
          image[i][j] = 1;
      } else {
        image[i][j]=-1;
      }
    }
  }
  int counter=0;
  int temp;

  for(int i=yMax-1;i>=0;--i){
      temp = 0;
      int sub=0;
    for(int j=xMax-1;j>=0;--j){
      sub = image[i][j] - temp;
  //cout << "sub: " << i << " / " << j << " : " << sub << "\n";
      if(sub!=0){
        ++counter;
        temp +=sub;
      }
        for(int k=i-1;k>=0;--k){
          image[k][j]-=temp;
        }
    }


  }



  cout << counter;

  return 0;
}
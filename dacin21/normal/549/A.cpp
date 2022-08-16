#include <iostream>
#include <fstream>
#include <vector>
#include <set>


using namespace std;

int main()
{
  /*ifstream is("in.txt");
    cin.rdbuf(is.rdbuf());*/

    int xMax, yMax;
    cin >> yMax >> xMax;

    vector<vector<char>> image(yMax, vector<char>(xMax, ' '));
    char tmp;
    for(int i=0;i<yMax;++i){
      for(int j=0;j<xMax;++j){
        cin >> tmp;
        switch(tmp){
        case 'f':
          tmp = 0;
          break;
        case 'a':
          tmp = 1;
          break;
        case 'c':
          tmp = 2;
          break;
        case 'e':
          tmp = 3;
          break;
        default:
          tmp = 5;
          break;
        }
        image[i][j] = tmp;
      }
    }
    int counter = 0;

    for(int i=0;i<yMax-1;++i){
      for(int j=0;j<xMax-1;++j){
          int is[6] = {0, 0, 0, 0, 0, 0};
          is[image[i][j]] = 1;
          is[image[i+1][j]] = 1;
          is[image[i+1][j+1]] = 1;
          is[image[i][j+1]] = 1;

          counter+=is[0]&is[1]&is[2]&is[3];
      }
    }




    cout << counter;
    return 0;
}
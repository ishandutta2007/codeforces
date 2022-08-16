#include <iostream>
#include <queue>


using namespace std;

int main()
{
  int N;
  cin >> N;
  int /*oldH,*/oldX, newH, newX, curH, curX;
  if(N<3){
    cout << N;
    return 0;
  }
  cin >> curX >> curH;
  cin >> newX >> newH;

  int count = 2;//last & first

  for(int i=2;i<N;++i){
    //oldH=curH;
    oldX=curX;
    curH=newH;
    curX=newX;
    cin >> newX >> newH;

    if(curX-curH > oldX){
      ++count;
      continue;
    }
    if(curX < newX - curH){
      curX+=curH;
      ++count;
    }

  }

  cout << count;

  return 0;
}
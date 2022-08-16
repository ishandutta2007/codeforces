#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>


using namespace std;

int main()
{
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double ret = 1e25;
  for(int i=1;i<=8;++i){

      b*=-1;
      if(!(i&1)) c*=-1;
      if(!(i&3)) d*=-1;
      if(i==1 ||i == 2 || i == 4 ||i==7 ) continue;
      double top = ((double)a)*d-((double)b)*c;
      double bot = ((double)a)+b+c+d;

      if(fabs(top)< 0.1) {
          ret = 0.0000000000f;
      }

      if(fabs(bot)> 0.1){
        double res = top / bot;
        if(abs(res) < ret){
          //cout << ret <<" <- "  <<a << " " <<b << " "<<c << " "<<d  <<  "\n";
          ret = abs(res);
        }
      }

  }
  cout.precision(15);

  cout << ret;
  return 0;
}
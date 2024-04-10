#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int MAX_INT = 1e9;

int main(){
    int a[50][50],b[50][50],na,nb,ma,mb;
    cin >> na >> ma;
    for (int i=0;i<na;i++)
        for (int j=0;j<ma;j++){
            char c;
            cin >> c;
            a[i][j] = c-'0';
        }
    cin >> nb >> mb;
    for (int i=0;i<nb;i++)
        for (int j=0;j<mb;j++){
            char c;
            cin >> c;
            b[i][j]=c-'0';
        }
    int xa=51,ya=51,as=0;
    for (int x=-51;x<=51;x++)
        for (int y=-51;y<=51;y++){
            int sum = 0;
            for (int i=0;i<na;i++)
                for (int j=0;j<ma;j++)
                    if (i+x<nb && j+y<mb && i+x>=0 && j+y>=0)
                       sum += (a[i][j]*b[i+x][j+y]);
            if (sum>as){
               as = sum;
               xa = x;
               ya = y;
            }
        }
    cout << xa << " " << ya << endl;
   // system("pause");
    return 0;
}
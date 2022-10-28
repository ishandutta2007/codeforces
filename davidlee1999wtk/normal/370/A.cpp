#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std;
int main()
{
    int r_1,r_2,c_1,c_2,dis;
    cin>>r_1>>c_1>>r_2>>c_2;
    if(r_1==r_2&&c_1==c_2)
    {
      printf("0 0 0\n");
      return 0;
    }
    if(r_1==r_2||c_1==c_2)
      printf("1 ");
    else
      printf("2 ");
    if(abs(r_1-c_1)%2!=abs(r_2-c_2)%2)
        printf("0 ");
    else  if(r_1-c_1==r_2-c_2||r_1+c_1==r_2+c_2)
        printf("1 ");
    else
        printf("2 ");
    dis=max(abs(r_1-r_2),abs(c_1-c_2));
    cout<<dis;
    return 0;
}
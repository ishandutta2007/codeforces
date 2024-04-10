#include<bits/stdc++.h>
using namespace std;

int dxv[] = {1,1,1,1};
int dyv[] = {1,2,3,4};
int dxh[] = {3,3};
int dyh[] = {1,3};
string st;
int vertcnt, horicnt;

int main(){
  cin>>st;
  for (auto i : st){
    if (i == '1'){
      cout << dxh[horicnt] << ' ' << dyh[horicnt] << '\n';
      horicnt = (horicnt + 1)%2;
    }
    else {
      cout << dxv[vertcnt] << ' ' << dyv[vertcnt] << '\n';
      vertcnt = (vertcnt + 1)%4;
    }
  }  
}
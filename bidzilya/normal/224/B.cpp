#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <string>
#include <fstream>
#include <set>
#include <map>
#include <queue>
using namespace std;

typedef long long ll;
const ll MD = 1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = 1e9;
const ll MAX_LL = 1e18;
const double eps = 1e-8;

int cnt[100001];
int n,k,x;
int a[100000];

int main(){
    cin >> n >> k;
    for (int i=1;i<=100000;i++)cnt[i]=0;
    for (int i=0;i<n;i++){cin >> a[i]; cnt[a[i]]++;}
    x=0;
    for (int i=1;i<=100000;i++)
        x += (cnt[i]>0);
    if (x<k){
       cout << -1 << " " << -1 << endl;
       //system("pause");
       return 0;
    }
    int l=0,r=n-1;
    while (true){
          int left = a[l];
          int right = a[r];
          int xx = x-(cnt[left]==1);
          if (xx>=k){
             l++;
             cnt[left]--;
             x = xx;
             continue;
          }
          xx = x-(cnt[right]==1);
          if (xx>=k){
             r--;
             cnt[right]--;
             x = xx;
             continue;
          }
          break;
    }
    cout << (l+1) << " " << (r+1) << endl;
   // system("pause");
    return 0;
}
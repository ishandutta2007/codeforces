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

int s,k;
int a[60];
int sz;

int main(){
    cin >> s >> k;
    a[0]=0;
    a[1]=1;
    sz = 2;
    for (sz=2;a[sz-1]<=MAX_INT;sz++){
        int tm = k;
        int j = sz-1;
        a[sz] = 0;
        while (tm>0 && a[j]>0){
              a[sz] += a[j];
              tm--;j--;
        }
    }
    vector<int> ans;
    for (int i=sz-1;i>0;i--){
        int tm = s/a[i];
        for (int j=0;j<tm;j++)ans.push_back(a[i]);
        s %= a[i];
    }
    if (ans.size()==1)ans.push_back(0);
    cout << ans.size() << endl;
    for (int i=0;i<ans.size();i++)
        cout << ans[i] << " ";
    cout << endl;
              
   // system("pause");
    return 0;
}
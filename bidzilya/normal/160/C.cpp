#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

typedef long long ll;
const ll MD = (ll)1e9 + 7;
const double PI = 3.1415926535;
const int MAX_INT = (int)1e9;
const ll MAX_LL = (ll)1e18;
const double eps = 1e-8;

int n;
ll k;
int a[100000];
int cnt[100000];
int b[100000];

int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++)
        cin >> a[i];
    sort(a,a+n);
    cnt[0] = 1;
    int j = 0;
    b[0] = a[0];
    for (int i=1;i<n;i++)
        if (a[i]==b[j])
            cnt[j]++;
        else{
            j++;
            cnt[j]=1;
            b[j] = a[i];
        }
    k--;
    for (int i=0;i<=j;i++)
        if (k>=1LL*cnt[i]*n)
            k-= 1LL*cnt[i]*n;
        else{
            cout << b[i] << " " << a[k/cnt[i]] << endl;
            break;
        }
    return 0;
}
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

const int NMAX = 100000;

int a[NMAX];
int n,k;

int main(){
    cin >> n >> k;
    for (int i=0;i<n;i++)cin >> a[i];
    int right = n-1;
    int left = n-1;
    while (left>0 && a[left-1]==a[right])left--;
    int i = k-1;
    for (int itr=0;itr<2*n;itr++){
        int next = (right+1)%n;
        if (next==left){
                        cout << itr << endl;
                        return 0;
        }
        a[next]=a[i];
        i=(i+1)%n;
        if (a[next]!=a[right])left = next;
        right = next;
    }
    cout << -1 << endl;
    return 0;
}
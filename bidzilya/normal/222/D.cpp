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

int n,xx;
int a[NMAX],b[NMAX],x[NMAX],y[NMAX];

int find_pos(int score,int sx,int sy){
    int res = 0;
    int j = 0;
    for (int i=sx-1;i>=0;i--){
        while (j<sy && a[i]+b[j]<score)j++;
        if (j>=sy)break;
        res++;
        j++;
    }
    return res;
}   

int main(){
    scanf("%d%d",&n,&xx);
    for (int i=0;i<n;i++)scanf("%d",&a[i]);
    for (int i=0;i<n;i++)scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n);
    printf("1 %d\n",find_pos(xx,n,n));
//    system("pause");
    return 0;
}
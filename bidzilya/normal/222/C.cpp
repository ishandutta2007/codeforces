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
const int U = 10000000;

int next[U+1];
int st[U+1];
int a[NMAX],b[NMAX];
int n,m;

int main(){
    for (int i=0;i<=U;i++)next[i]=st[i]=0;
    for (int i=2;i<=U;i++)
        if (!next[i]){
           int j = 1;
           while (j*i<=U){next[j*i]=i;j++;}
        }
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++){                                      
        scanf("%d",&a[i]);
        int x = a[i];
        while (x>1){
              st[next[x]]++;
              x /= next[x];
        }
    }
    for (int i=0;i<m;i++){
        scanf("%d",&b[i]);
        int x = b[i];
        while (x>1){
              st[next[x]]--;
              x /= next[x];
        }
    }
    for (int i=0;i<n;i++){
        int res = 1;
        int x = a[i];
        while (x>1){
              if (st[next[x]]>0){
                 st[next[x]]--;
                 res *= next[x];
              }
              x /= next[x];
        }
        a[i] = res;
    }
    for (int i=0;i<m;i++){
        int res = 1;
        int x = b[i];
        while (x>1){
              if (st[next[x]]<0){
                 st[next[x]]++;
                 res *= next[x];
              }
              x /= next[x];
        }
        b[i] = res;
    }
    printf("%d %d\n",n,m);
    for (int i=0;i<n;i++)printf("%d ",a[i]);
    printf("\n");
    for (int i=0;i<m;i++)printf("%d ",b[i]);
    printf("\n");
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

using namespace std;

int Q[30001],f=0,r=0;
int C[30001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int n,m;
    scanf("%d %d",&n,&m);

    Q[++f] = n;
    C[n] = 1;
    while(true){
        n = Q[++r];
        if(n*2 < 30000 && C[n*2] == 0){
            Q[++f] = n*2;
            C[n*2] = C[n] + 1;
            if(n*2 == m) break;
        }
        if(n-1 > 0 && C[n-1] == 0){
            Q[++f] = n-1;
            C[n-1] = C[n] + 1;
            if(n-1 == m) break;
        }
    }
    printf("%d\n",C[m]-1);

    return 0;
}
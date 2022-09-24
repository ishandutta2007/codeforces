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

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int N,M;
    scanf("%d %d",&N,&M);

    int n,m,a=0;
    m=0;
    while(1){
        if((N-m) < 0) break;
        else if(M-(2*m) < 0) break;
        n = min((N-m)/2,(M-(2*m)));
        a = max(a,(m+n));
        m++;
    }

    printf("%d\n",a);

    return 0;
}
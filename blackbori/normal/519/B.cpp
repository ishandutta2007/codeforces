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

int E1[100001],E2[100001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdin);

    int n,i,k;
    scanf("%d",&n);

    for(i=0; i<n; i++){
        scanf("%d",&E1[i]);
    }
    sort(E1,E1+n);
    for(i=0; i<n-1; i++){
        scanf("%d",&E2[i]);
    }
    sort(E2,E2+n-1);
    E2[n-1] = 0;
    for(i=0; i<n; i++){
        if(E1[i] != E2[i]) break;
    }
    printf("%d\n",E1[i]);
    k = E1[i];

    for(i=0; i<n-2; i++){
        scanf("%d",&E2[i]);
    }
    E2[n-2] = k;
    sort(E2,E2+n-1);
    E2[n-1] = 0;
    for(i=0; i<n; i++){
        if(E1[i] != E2[i]) break;
    }
    printf("%d\n",E1[i]);

    return 0;
}
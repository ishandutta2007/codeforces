#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;
int main() {
    int n;
    cin>>n;
    cout<<n*3+4<<endl;
    printf("0 0\n0 1\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",i,i-1);
        printf("%d %d\n",i,i);
        printf("%d %d\n",i,i+1);
    }
    printf("%d %d\n%d %d\n",n+1,n,n+1,n+1);
    return 0;
}
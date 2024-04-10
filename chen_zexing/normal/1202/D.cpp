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
#include <bitset>
#include <vector>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--) {
        int l=1,n;
        cin>>n;
        while (l*(l-1)/2<=n) l++;
        l--;
        printf("133");
        for(int i=1;i<=n-l*(l-1)/2;i++) printf("7");
        for(int i=3;i<=l;i++) printf("3");
        printf("7");
        printf("\n");
    }
}
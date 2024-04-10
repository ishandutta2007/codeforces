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
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        if(n%2==0) printf("%d %d\n",n/2,n/2);
        else{
            int f=1;
            for(int i=2;i<=sqrt(n);i++)
            {
                if(n%i==0)
                {
                    printf("%d %d\n",n/i,n-n/i);
                    f=0;
                    break;
                }
            }
            if(f) printf("1 %d\n",n-1);
        }
    }
}
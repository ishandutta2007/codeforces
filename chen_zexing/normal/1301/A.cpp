#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
char a[105],b[105],c[105];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int f=1;
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",c);
        int l=strlen(a);
        for(int i=0;i<l;i++)
            if(c[i]!=a[i]&&c[i]!=b[i])
                f=0;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
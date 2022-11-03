#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

char str[1000006];
int ans[1000006];

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    gets(str);
    int n=strlen(str),l=0,r=n-1;
    for(int i=0;i<n;++i) {
        if (str[i]=='l') ans[r--]=i;
        else ans[l++]=i;
    }
    for(int i=0;i<n;++i)
        printf("%d\n",ans[i]+1);
    return 0;
}
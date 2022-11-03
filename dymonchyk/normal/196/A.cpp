#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <memory.h>

using namespace std;

char str[100002];
char mx[100002];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(str);
    int n=strlen(str);
    for(int i=n-1;i>=0;--i) mx[i]=max(str[i],mx[i+1]);
    for(int i=0;i<n;++i) {
        if (str[i]==mx[i]) printf("%c",str[i]);
    }
    printf("\n");
    return 0;
}
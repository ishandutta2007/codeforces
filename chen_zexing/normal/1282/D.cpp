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
using namespace std;
char s[305];
int main() {
    int ca,cb,t;
    for(int i=1;i<=300;i++) printf("a");
    printf("\n");
    fflush(stdout);
    scanf("%d",&ca),ca=300-ca;
    for(int i=1;i<=300;i++) printf("b");
    printf("\n");
    fflush(stdout);
    scanf("%d",&cb),cb=300-cb;
    for(int i=1;i<=ca+cb;i++) s[i]='a';
    int rb=cb;
    if(cb==0){
        for(int i=1;i<=ca+cb;i++) printf("%c",s[i]);
        printf("\n");
        return 0;
    }
    for(int i=1;i<=ca+cb;i++){
        s[i]='b';
        for(int j=1;j<=ca+cb;j++) printf("%c",s[j]);
        printf("\n");
        fflush(stdout);
        scanf("%d",&t);
        if(t==0) return 0;
        if(t==rb-1) rb--;
        else s[i]='a';
    }
    return 0;
}
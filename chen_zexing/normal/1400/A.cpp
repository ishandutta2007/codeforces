#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
char s[100];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=2*n-1;i+=2) printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}
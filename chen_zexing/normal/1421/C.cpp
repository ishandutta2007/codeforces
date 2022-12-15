#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
using namespace std;
char s[100005];
int main() {
    scanf("%s",s);
    int l=strlen(s);
    printf("3\n");
    printf("L %d\n",l-1);
    printf("R %d\n",l-1);
    printf("R %d\n",2*l-1);
    return 0;
}
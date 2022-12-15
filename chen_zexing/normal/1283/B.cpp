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
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int a,b;
        scanf("%d%d",&a,&b);
        if(a%b<=b/2) printf("%d\n",a);
        else printf("%d\n",a-a%b+b/2);
    }
    return 0;
}
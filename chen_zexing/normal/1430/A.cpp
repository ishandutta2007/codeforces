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
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        if(n==1||n==2||n==4) puts("-1");
        else if(n%3==0) printf("%d 0 0\n",n/3);
        else if(n%3==1) printf("%d 0 1\n",(n-7)/3);
        else printf("%d 1 0\n",(n-5)/3);
    }
    return 0;
}
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
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        if(k<n){
            if(n%k==0) printf("1\n");
            else printf("%d\n",2);
        }
        else printf("%d\n",k/n+(k%n>0));
    }
    return 0;
}
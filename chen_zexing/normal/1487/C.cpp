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
    while(T--) {
        int n;
        scanf("%d",&n);
        if(n%2==0){
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(j==i+n/2) printf("0 ");
                    else if(j<i+n/2) printf("1 ");
                    else printf("-1 ");
                }
            }
        }
        else{
            for(int i=1;i<n;i++)
                for(int j=i+1;j<=n;j++){
                    if(j<=i+n/2) printf("1 ");
                    else printf("-1 ");
                }
        }
        puts("");
    }
    return 0;
}
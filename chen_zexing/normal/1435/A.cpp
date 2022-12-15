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
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        int x,y;
        cin>>n;
        for(int i=1;i<=n/2;i++){
            scanf("%d%d",&x,&y);
            printf("%d %d ",y,-x);
        }
        printf("\n");
    }
    return 0;
}
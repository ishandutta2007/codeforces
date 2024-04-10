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
vector <int> v[305];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=(i-1)*(n/2)+1;j<=i*(n/2);j++)
                v[i].push_back(j),v[i].push_back(n*(n/2*2)-j+1);
        if(n%2) for(int i=n*(n-1)+1;i<=n*n;i++) v[i-n*(n-1)].push_back(i);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=0;j<v[i].size();j++)
                printf("%d ",v[i][j]);
    }
    return 0;
}
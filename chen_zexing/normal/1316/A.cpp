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
int a[100005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        long long sum=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        if(sum<m) cout<<sum<<endl;
        else cout<<m<<endl;
    }
    return 0;
}
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
bool cmp(int a,int b){return a>b;}
int main() {
    int n;
    char s[105];
    cin>>n;
    scanf("%s",s+1);
    int a[4]={0,2,19,6};
    int ans=99999;
    for(int i=1;i<=n-3;i++){
        int cnt=0;
        for(int k=i;k<=i+3;k++) {
            int mn = 200;
            mn = min(mn, abs(a[k-i] - s[k] + 'A')), mn = min(mn, 26 - abs(a[k-i] - s[k] + 'A'));
            cnt += mn;
        }
        ans=min(ans,cnt);
    }
    cout<<ans<<endl;
    return 0;
}
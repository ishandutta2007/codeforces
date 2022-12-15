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
int a[200005];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,cnt1=0,cnt2=0,rest=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            rest+=a[i]-a[i-1]-1;
            if(rest) cnt1++,rest--;
        }
        rest=0,a[n+1]=2*n+1;
        for(int i=n;i>=1;i--)
        {
            rest+=a[i+1]-a[i]-1;
            if(rest) cnt2++,rest--;
        }
        cnt1=n-cnt1;
        cout<<cnt2-cnt1+1<<endl;
    }
    return 0;
}
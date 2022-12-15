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
int mn[200005],mx[200005],f1[200005],f2[200005];
queue <int> q1;
priority_queue <int> q2;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f1[i]=f2[i]=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=a[i-1]){
                mn[i]=mx[i]=a[i];
                for(int j=a[i-1]+1;j<a[i];j++) q1.push(j),q2.push(j);
            }
            else{
                mn[i]=q1.front(),mx[i]=q2.top();
                q1.pop(),q2.pop();
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",mn[i]);
        puts("");
        for(int i=1;i<=n;i++) printf("%d ",mx[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
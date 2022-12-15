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
int a[1000005],b[1000005];
int main() {
    //ios::sync_with_stdio(false);
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    int p1,p2;
    for(int i=0;i<n;i++)
        if(a[i]%p) {
            p1 = i;
            break;
        }
    for(int i=0;i<m;i++)
        if(b[i]%p){
            p2=i;
            break;
        }
    cout<<p1+p2<<endl;
    return 0;
}
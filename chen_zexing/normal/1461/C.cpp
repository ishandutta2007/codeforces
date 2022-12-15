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
        double ans=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int pos=n;
        while(pos&&a[pos]==pos) pos--;
        if(pos==0){
            puts("1");
        }
        for(int i=1;i<=m;i++){
            int r;
            double p;
            scanf("%d%lf",&r,&p);
            if(r>=pos) ans*=1-p;
        }
        if(pos==0) continue;
        printf("%.8lf\n",1-ans);
    }
    return 0;
}
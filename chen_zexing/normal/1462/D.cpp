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
int a[3005];
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        long long sum=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        vector <int> v;
        int ff=0;
        for(int i=n;i>=1;i--){
            if(sum%i) continue;
            long long t=sum/i;
            int f=1,now=0;
            for(int j=1;j<=n;j++){
                if(now+a[j]==t) now=0;
                else if(now+a[j]<t) now+=a[j];
                else{
                    f=0;
                    break;
                }
            }
            if(f){
                ff=1;
                printf("%d\n",n-i);
                break;
            }
        }
    }
    return 0;
}
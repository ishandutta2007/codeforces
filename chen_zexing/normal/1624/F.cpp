#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
int query(int x){
    printf("+ %d\n",x);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int main() {
    int T = 1;
    //cin >> T;
    while(T--) {
        int n,tot=0,cnt=0,lst=0;
        cin>>n;
        int l=1,r=n-1;
        while(l<r){
            int mid=(l+r)/2+1,v=n-mid;
            int temp=query(v);
            tot+=v;
            if(temp>lst){
                cnt++;
                l=(mid+v)%n,r=(r+v)%n;
            }
            else l=(l+v)%n,r=(mid-1+v)%n;
            lst=temp;
        }
        printf("! %d\n",cnt*n+l);
    }
    return 0;
}
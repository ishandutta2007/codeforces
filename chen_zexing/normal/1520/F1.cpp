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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int query(int l,int r){
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,t,k;
        cin>>n>>t>>k;
        int l=1,r=n;
        while(l<r){
            int mid=(l+r)>>1;
            int temp=query(l,mid);
            if(mid-l+1-temp>=k) r=mid;
            else k-=mid-l+1-temp,l=mid+1;
            //cout<<k<<" "<<l<<" "<<r<<endl;
        }
        cout<<"!"<<" "<<l<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
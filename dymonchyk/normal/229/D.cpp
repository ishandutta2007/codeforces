#include <cstdio>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>

using namespace std;

int arr[100002],dp[100002],ans[100002];
int sum[100002],barrier[100002];

int get(int l,int r) {
    return sum[r]-(l>0 ? sum[l-1] : 0);
}

vector < int > q;

int main() {
//  freopen("input.txt","r", stdin);
//  freopen("output.txt", "w", stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%d",&arr[i]);
    }
    reverse(arr,arr+n);
    for(int i=0;i<n;++i) {
        sum[i]=arr[i];
        if (i) sum[i]+=sum[i-1];
    }
/*  cout << n << endl;
    for(int i=0;i<n;++i)
        cout << arr[i] << " ";
    cout << endl;
*/  dp[n]=ans[n]=0; barrier[n]=sum[n]=sum[n-1];
    q.push_back(n);
    for(int i=n-1;i>=0;--i) {
        int l=0,r=q.size();
        while(r-l>1) {
            int m=(l+r)>>1;
            if ((i>0 ? sum[i-1] : 0)<=barrier[q[m]]) l=m;
            else r=m;
        }
        dp[i]=get(i,q[l]-1);
        ans[i]=ans[q[l]]+1; barrier[i]=2*(i>0 ? sum[i-1] : 0)-sum[q[l]-1];
        while(q.size()>1&&barrier[q.back()]<=barrier[i]) q.pop_back();
        q.push_back(i);
    }
    printf("%d\n",n-ans[0]);
    return 0;
}
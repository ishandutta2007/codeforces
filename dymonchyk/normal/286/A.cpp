#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int arr[100005];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    cerr << n << endl;
    if (n==1) puts("1");
    else if (n==2||n%4==3||n%4==2) puts("-1");
    else {
        for(int i=1;i<=n;++i)
            arr[i]=i;
        int l=1,r=n;
        while(r-l>=3) {
            arr[l]=l+1;
            arr[l+1]=r;
            arr[r-1]=l;
            arr[r]=r-1;
            l+=2; r-=2;
        }
        for(int i=1;i<=n;++i) {
            if (i!=1) printf(" ");
            printf("%d",arr[i]);
        }
        printf("\n");
    }
    return 0;
}
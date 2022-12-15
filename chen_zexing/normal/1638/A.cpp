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
#include <assert.h>
using namespace std;
int a[505];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,pos=-1;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            if(a[i]!=i){
                for(int j=i+1;j<=n;j++) if(a[j]==i){
                        pos=j;
                        break;
                    }
                for(int j=i;i+pos-j>j;j++) swap(a[j],a[i+pos-j]);
                break;
            }
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}
//unordered_map
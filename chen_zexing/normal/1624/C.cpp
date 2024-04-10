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
int f[55],a[55];
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) f[i]=0;
        for(int i=1,x;i<=n;i++){
            scanf("%d",&x);
            while(x){
                if(x<=n&&f[x]==0){
                    f[x]=1;
                    break;
                }
                x/=2;
            }
        }
        int ff=1;
        for(int i=1;i<=n;i++) if(f[i]==0) ff=0;
        puts(ff?"YES":"NO");
    }
    return 0;
}
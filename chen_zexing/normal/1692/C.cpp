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
#include <random>
using namespace std;
char s[15][15];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n=8,m=8,fl=0;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=2;i<n&&!fl;i++)
            for(int j=2;j<m&&!fl;j++){
                int f=1;
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=n;l++)
                        if(i+j!=k+l&&i-j!=k-l&&s[k][l]=='#'||(i+j==k+l||i-j==k-l)&&s[k][l]=='.')
                            f=0;
                if(f) fl=1,cout<<i<<" "<<j<<endl;
            }
    }
    return 0;
}
//cf
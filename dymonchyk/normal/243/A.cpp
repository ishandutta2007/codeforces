#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <queue>
#include <ctime>
#include <complex>
#include <map>
#include <set>
//#pragma comment (linker,"/STACK:128000000")

using namespace std;

int arr[100005];
int wh[100005][22];
set <int> f;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&arr[i]);
    for(int i=0;i<=20;++i)
        wh[n][i]=n;
    for(int i=n-1;i>=0;--i) {
        memcpy(wh[i],wh[i+1],sizeof(wh[i]));
        for(int j=0;j<=20;++j) {
            if (arr[i]&(1<<j)) wh[i][j]=i;
        }
    }
    int ans=0;
    for(int i=0;i<n;++i) {
        int cur=i,val=arr[i];
        while(cur!=n) {
            f.insert(val);
            ++ans; int npos=n;
            for(int j=0;j<=20;++j)
                if (val&(1<<j));
                else npos=min(npos,wh[cur+1][j]);
            cur=npos; val|=arr[cur];
        }
    }
    cout << f.size() << endl;
    return 0;
}
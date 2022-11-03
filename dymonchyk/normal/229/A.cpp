#include <cmath>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#pragma comment (linker,"/STACK:128000000")

using namespace std;

char arr[101][30002];
int l[101][30002];
int r[101][30002];


int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m;
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<n;++i) {
        scanf("%s",&arr[i]);
        for(int j=0;j<m;++j)
            arr[i][j+m]=arr[i][j+m+m]=arr[i][j];
    }
    for(int i=0;i<n;++i) {
        l[i][0]=(arr[i][0]=='1' ? 0 : -1);
        for(int j=1;j<3*m;++j) {
            l[i][j]=l[i][j-1];
            if (arr[i][j]=='1') l[i][j]=j;
        }
        r[i][3*m-1]=(arr[i][3*m-1]=='1' ? 3*m-1 : -1);
        for(int j=3*m-2;j>=0;--j) {
            r[i][j]=r[i][j+1];
            if (arr[i][j]=='1') r[i][j]=j;
        }
    }
    int ans=-1;
    for(int j=0;j<3*m;++j) {
        int cur=0;
        for(int i=0;i<n;++i) {
            if (l[i][j]==-1&&r[i][j]==-1) {
                cur=-1;
                break;
            }
            int val=-1;
            if (l[i][j]!=-1) val=abs(j-l[i][j]);
            if (r[i][j]!=-1) {
                if (val==-1||val>abs(j-r[i][j])) val=abs(j-r[i][j]);
            }
            cur+=val;
//          cur+=min(abs(j-l[i][j]),abs(j-r[i][j]));
        }
        if (cur!=-1&&(ans==-1||ans>cur)) ans=cur;
//      cout << j << "  " << cur << endl;
    }
    printf("%d\n",ans);
    return 0;
}
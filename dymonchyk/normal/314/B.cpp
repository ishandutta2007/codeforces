#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <memory.h>

using namespace std;

char a[102],c[102];
int how[42][102];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int b,d;
    scanf("%d%d\n",&b,&d);
    gets(a); gets(c);
    int la=strlen(a),lc=strlen(c);
    for(int pos=0;pos<lc;++pos) {
        int cnt=0,cur=pos;
        for(int i=0;i<la;++i) {
            if (a[i]==c[cur]) {
                ++cnt;
                ++cur;
                if (cur==lc) cur=0;
            }
        }
        how[0][pos]=cnt;
    }
    for(int i=1;i<=30;++i) {
        for(int pos=0;pos<lc;++pos) {
            int nx=(pos+how[i-1][pos])%lc;
            how[i][pos]=how[i-1][pos]+how[i-1][nx];
        }
    }
    int total=0,cur=0;
    for(int i=30;i>=0;--i) {
        if (b>=(1<<i)) {
            total+=how[i][cur];
            cur=total%lc;
            b-=(1<<i);
        }
    }
    printf("%d\n",total/(lc*d));
    return 0;
}
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
#include <memory.h>

using namespace std;

char str[6000006];
char * words[1000006];
int lens[1000006],go[1000006][20];
int sum[1000006];

int get(int l,int r) {
    if (l>r) return 0;
    return sum[r]-(l>0 ? sum[l-1]+1 : 0);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,r,c;
    scanf("%d%d%d\n",&n,&r,&c);
    gets(str);
    int cur=0,clen=0,len=strlen(str); str[len++]=' ';
    words[0]=&str[0];
    for(int i=0;i<len;++i) {
        if (str[i]==' ') {
            lens[cur]=clen; clen=0;
            words[cur+1]=&str[i+1];
            ++cur; str[i]='\0';
        } else {
            ++clen;
        }
    }
//  for(int i=0;i<n;++i)
//      cout << words[i] << "   " << lens[i] << endl;
    sum[0]=lens[0];
    for(int i=1;i<n;++i)
        sum[i]=1+sum[i-1]+lens[i];
    for(int i=0;i<n;++i) {
        int l=i-1,r=n;
        while(r-l>1) {
            int m=(l+r)>>1;
            if (get(i,m)<=c) l=m;
            else r=m;
        }
        go[i][0]=l;
//      cout << nx[i] << endl;
    }
    for(int j=0;j<20;++j) go[n][j]=n-1;
    for(int i=n-1;i>=0;--i) {
        for(int j=1;j<20;++j)
            go[i][j]=go[go[i][j-1]+1][j-1];
    }
    int best=0,pos=-1;
    for(int i=0;i<n;++i) {
        int cur=i,left=r;
        for(int j=19;j>=0;--j)
            if (left>=(1<<j)) {
                left-=(1<<j);
                cur=go[cur][j]+1;
            }
        if (cur-i>best) {
            best=cur-i;
            pos=i;
        }
    }
    if (pos!=-1) {
        for(int i=0;i<r&&pos<n;++i) {
            int nx=go[pos][0]+1;
            for(int j=pos;j<nx;++j) {
                if (j!=pos) printf(" ");
                printf("%s",words[j]);
            }
            printf("\n");
            pos=nx;
        }
    }
    return 0;
}
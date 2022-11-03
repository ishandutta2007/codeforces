#include <cmath>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <ctime>

using namespace std;

char s[200002],t[200002];
int wh[200002][26];

void go(int ret[200002]) {
    int n=strlen(s),m=strlen(t);
    for(int i=0;i<26;++i)
        wh[0][i]=-1;
    wh[0][t[0]-'a']=0;
    for(int i=1;i<m;++i) {
        memcpy(wh[i],wh[i-1],sizeof(wh[i]));
        wh[i][t[i]-'a']=i;
    }
    memcpy(wh[m],wh[m-1],sizeof(wh[m]));
    int can=0;
    for(int i=0;i<n;++i) {
        int pos=wh[can][s[i]-'a'];
        ret[i]=pos;
        if (pos==can) ++can;
    }
}

int arr1[200002],arr2[200002];

void rev(char * s) {
    int n=strlen(s);
    int l=0,r=n-1;
    while(l<r) {
        swap(s[l],s[r]);
        ++l; --r;
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    gets(s); gets(t);
    go(arr1);
    rev(s); rev(t);
    go(arr2);
    int len=strlen(t);
    for(int i=strlen(s)-1;i>=0;--i)
        arr2[i]=len-1-arr2[i];
    int l=0,r=strlen(s)-1;
    while(l<r) {
        swap(arr2[l],arr2[r]);
        l++; --r;
    }
    bool ok=true;
    for(int i=strlen(s)-1;i>=0;--i)
        if (arr1[i]<arr2[i]) {
            ok=false;
            break;
        }
        puts(ok ? "Yes" : "No");
    return 0;
}
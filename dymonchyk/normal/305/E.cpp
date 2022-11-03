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

int g[5002];

int go(int n) {
    if (n<3) return 0;
    if (g[n]!=-1) return g[n];
    vector <int> v;
    for(int i=1;i<n-1;++i) {
        v.push_back(go(i)^go(n-1-i));
    }
    sort(v.begin(),v.end());
    int ret=0;
    for(int i=0;i<v.size();++i) {
        if (v[i]>ret) break;
        if (v[i]==ret) ++ret;
    }
    return g[n]=ret;
}

char str[5005];

bool win(int move) {
    vector <int> v;
    int len=strlen(str),cur=0;
    for(int i=1;i<len-1;++i) {
        if (abs(i-move)>1&&str[i-1]==str[i+1]) cur++;
        else {
            if (cur>0) v.push_back(cur+2);
            cur=0;
        }
    }
    if (cur>0) v.push_back(cur+2);
    int x=0;
    for(int i=0;i<v.size();++i)
        x^=go(v[i]);
    return x==0;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    memset(g,-1,sizeof(g));
    for(int i=0;i<=5000;++i) go(i);
    gets(str);
    int n=strlen(str);
    for(int i=1;i<n-1;++i)
        if (str[i-1]==str[i+1]&&win(i)) {
            puts("First");
            printf("%d\n",i+1);
            return 0;
        }
    puts("Second");
    return 0;
}
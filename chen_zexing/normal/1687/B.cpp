#pragma GCC optimize("Ofast,unroll-loops")
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
char s[505];
int w[505],id[505];
int n,m;
int query(){
    printf("? ");
    for(int i=1;i<=m;i++) printf("%c",s[i]);
    puts(""),fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
bool cmp(int a,int b){
    return w[a]<w[b];
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--) {
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            id[i]=i;
            for(int j=1;j<=m;j++) s[j]=j==i?'1':'0';
            w[i]=query();
        }
        sort(id+1,id+m+1,cmp);
        for(int i=1;i<=m;i++) s[i]='0';
        int lst=0;
        for(int i=1;i<=m;i++){
            s[id[i]]='1';
            int temp=query();
            if(temp==lst+w[id[i]]) lst=temp;
            else s[id[i]]='0';
        }
        printf("! %d\n",lst);
    }
    return 0;
}
//unordered_map
//cf
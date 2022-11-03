#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <map>
#pragma comment("/:STACK:64000000",linker)

using namespace std;

char s1[200002],s2[200002];
long long cnt[200002][26],sum;

double solve(char * str1,char * str2,bool need = true) {
    memset(cnt,0,sizeof(cnt));
    int n=strlen(str1);
    double ret=0;
    for(int i=0;i<n;++i) {
        if (need) cnt[i][str2[i]-'A']+=i+1;
        ret+=1.0*cnt[i][str1[i]-'A']*(n-i)/sum;
        if (!need) cnt[i][str2[i]-'A']+=i+1;
        for(int j=0;j<26;++j)
            cnt[i+1][j]=cnt[i][j];
    }
    return ret;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d\n",&n);
    gets(s1); gets(s2);
    long long cnt=0;
    for(int i=1;i<=n;++i)
        sum+=1LL*i*i;
    printf("%.9lf\n",solve(s1,s2)+solve(s2,s1,false));
    return 0;
}
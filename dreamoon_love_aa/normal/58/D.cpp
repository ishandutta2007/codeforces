#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
char c[3];
struct String{
    char s[12];
    bool operator<(String b)const{
        int i;
        for(i=0;s[i]&&b.s[i];i++)
            if(s[i]!=b.s[i])return s[i]<b.s[i];
        if(!s[i])return c[0]<b.s[i];
        if(!b.s[i])return s[i]<c[0];
        return 0;
    }
}a[10000];
vector<int>d[11];
int p[11],used[10000];
main(){
    int i,ma=0,mi=10,n,len;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%s",a[i].s);
    scanf("%s",c);
    sort(a,a+n);
    for(i=0;i<n;i++){
        d[strlen(a[i].s)].push_back(i);
        ma=max(ma,(int)strlen(a[i].s));
        mi=min(mi,(int)strlen(a[i].s));
    }
    for(i=0;i<n;i++){
        if(used[i])continue;
        printf("%s%c",a[i].s,c[0]);
        p[len=strlen(a[i].s)]++;
        used[d[ma+mi-len][p[ma+mi-len]]]=1;
        printf("%s\n",a[d[ma+mi-len][p[ma+mi-len]++]].s);
    }
}
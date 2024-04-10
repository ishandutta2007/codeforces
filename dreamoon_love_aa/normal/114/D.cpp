#include<stdio.h>
#include<set>
#include<string.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
const long long MOD=127;
char s[2048],head[2048],tail[2048];
long long hh,th;
int hl,tl,sl,d[2048];
vector<long long>haha;
long long hash(char gg[],int len){
    long long an=0;
    int i;
    for(i=0;i<len;i++){
        an*=MOD;
        an+=gg[i];
    }
    return an;
}
main(){
    int i,j;
    scanf("%s%s%s",s,head,tail);
    sl=strlen(s);
    hl=strlen(head);
    tl=strlen(tail);
    hh=hash(head,hl);
    th=hash(tail,tl);
    for(i=0;i+hl<=sl;i++)
        if(hash(s+i,hl)==hh)d[i]|=1;
    for(i=0;i+tl<=sl;i++)
        if(hash(s+i,tl)==th)d[i]|=2;
    int ma=max(hl,tl);
    for(i=0;i+ma<=sl;i++){
        if(d[i]&1){
            long long now=s[i];
            for(j=1;j<ma;j++){
                now*=MOD;
                now+=s[i+j];
            }
            for(j=i+ma;j<=sl;j++){
                if(d[j-tl]&2){
                    haha.push_back(now);
                }
                now*=MOD;
                now+=s[j];
            }
        }
    }
    sort(haha.begin(),haha.end());
    printf("%d\n",unique(haha.begin(),haha.end())-haha.begin());
    return 0;
}
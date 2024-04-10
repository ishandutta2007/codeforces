#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 100010
char s[SIZE],tmp[SIZE+SIZE];
int d[SIZE];
vector<int>a[26];
int Find(int x,int y,int k){
    if(a[x].size()==0)return k;
    if(d[x]==a[x].size())return y-a[x][d[x]-1];
    while(d[x]<a[x].size()&&a[x][d[x]]<=y)d[x]++;
    if(d[x]==a[x].size())return y-a[x][d[x]-1];
    if(d[x]==0)return a[x][0]-y;
    return min(a[x][d[x]]-y,y-a[x][d[x]-1]);
}
void Go(int k){
    long long an=0;
    int i,len;
    scanf("%s",tmp);
    len=strlen(tmp);
    for(i=0;i<26;i++)d[i]=0;
    for(i=0;tmp[i];i++)
        an+=Find(tmp[i]-'a',i,len);
    printf("%I64d\n",an);
}
main(){
    int n,k,i;
    scanf("%d%d",&n,&k);
    scanf("%s",s);
    for(i=0;s[i];i++)a[s[i]-'a'].push_back(i);
    while(n--)Go(k);
}
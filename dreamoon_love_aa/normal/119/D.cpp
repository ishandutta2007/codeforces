#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 1000010
#define MAX 1000000000
struct data{
    int x,get;
    bool operator<(data b)const{return get>b.get||(get==b.get&&x<b.x);}
}r[SIZE];
char s1[SIZE],s2[SIZE+SIZE],s3[SIZE+SIZE];
int l1,l2,d[SIZE+SIZE],d2[SIZE+SIZE];
vector<int>haha[SIZE];
int main(){
    int i,j,k,tail,an1,an2;
    gets(s1);
    gets(s2);
    l1=strlen(s1);
    l2=strlen(s2);
    if(l1!=l2){
        puts("-1 -1");
        return 0;
    }
    for(tail=0;tail<l1-1&&s1[tail]==s2[l2-1-tail];tail++);
    
    for(i=0;i<l2-1;i++)s2[i+l2]=s1[i];
    int left;
    for(i=1,left=0;s2[i];i++){
            if(i<left+d[left])
                k=min(d[i-left],left+d[left]-i);
            else
                k=0;
            for(;s2[i+k];k++){
                an2++;
                if(s2[i+k]!=s2[k])break;
            }
            d[i]=k;
            if(i+k>left+d[left])left=i;
        }
    for(i=0;i<l1;i++)s3[i]=s1[l1-1-i];
    for(i=0;i<l1;i++)s3[i+l1]=s2[i];
    for(i=1,left=0;s3[i];i++){
            if(i<left+d2[left])
                k=min(d2[i-left],left+d2[left]-i);
            else
                k=0;
            for(;s3[i+k];k++){
                an2++;
                if(s3[i+k]!=s3[k])break;
            }
            d2[i]=k;
            if(i+k>left+d2[left])left=i;
        }
    for(i=0;i<l1;i++)
        if(min(l2-1,d2[l2+i]+i-1)>=l1-tail-1)haha[min(l2-1,d2[l2+i]+i-1)].push_back(i);
    int mi=MAX;
    an1=MAX;
    for(j=0;j<haha[l1-1].size();j++){
        if(haha[l1-1][j]>l1-1)continue;
        mi=min(mi,haha[l1-1][j]);
    }
    for(i=1;i<=tail;i++){
        for(j=0;j<haha[l1-i-1].size();j++){
            if(haha[l1-i-1][j]>l1-i-1)continue;
            mi=min(mi,haha[l1-i-1][j]);
        }
        if(mi!=MAX&&i+mi>i-1&i+mi<l1&&d[l2+i]>=mi){
            an1=i-1;
            an2=an1+mi+1;
        }
    }
    if(an1==MAX)puts("-1 -1");
    else printf("%d %d\n",an1,an2);
    return 0;
}
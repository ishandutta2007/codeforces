#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
#define SIZE 111
char a[SIZE],c[SIZE];
int used[SIZE][SIZE],len[2],rn;
struct data{
    int pos1,pos2,tt;
    data(int _pos1=0,int _pos2=0,int _tt=0){pos1=_pos1;pos2=_pos2;tt=_tt;}
}r[100000];
vector<pair<int,int> >ha;
int main(){
    memset(used,-1,sizeof(used));
    int i=0,j=0,k,n,b,d;
    scanf("%d%d",&b,&d);
    scanf("%s%s",a,c);
    len[0]=strlen(a);
    len[1]=strlen(c);
    int now=0;
    while(1){
        int cnt=0;
        while(a[j]!=c[i]&&cnt<len[0]+1){
            j++;
            if(j==len[0]){j=0;now++;}
            cnt++;
        }
        if(cnt==len[0]+1){
            puts("0");
            return 0;
        }
        if(used[j][i]!=-1)break;
        used[j][i]=rn;
        r[rn++]=data(j,i,now);
        i++;
        if(i==len[1])i=0;
        j++;
        if(j==len[0]){
            now++;
            j=0;
        }
    }
    if(r[rn-1].tt>=b){
        for(i=0;i<rn&&r[i].tt<b;i++);
        printf("%d\n",i/len[1]/d);
    }
    else{
        int No=used[j][i];
        int dd=now-r[No].tt;
        for(k=0;r[No].tt+(long long)dd*k<b;k++);
        k--;
        for(i=No;i<rn&&r[i].tt+k*dd<b;i++);
        printf("%d\n",(int)((i+(long long)k*(rn-No))/len[1]/d));
    }
    return 0;
}
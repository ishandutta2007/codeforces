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
#define SIZE 200010
char s1[SIZE],s2[SIZE];
vector<int>d1[26],d2[26];
int ll[SIZE],rr[SIZE],l1,l2;
struct data{
    int x,y;
    data(int _x=0,int _y=0){x=_x,y=_y;}
    bool operator<(const data& b)const{return x<b.x||(x==b.x&&y<b.y);}
};
vector<data>qq[26];
int now[26];
int main(){
    int i,j,k,n;
    scanf("%s%s",s1,s2);
    l1=strlen(s1);
    l2=strlen(s2);
    for(i=0;i<l1;i++){
        d1[s1[i]-'a'].pb(i);
    }
    for(i=0;i<l2;i++){
        d2[s2[i]-'a'].pb(i);
    }
    for(i=0;i<26;i++){
        if(d1[i].size()<d2[i].size()){
            puts("No");
            return 0;
        }
    }
    for(i=j=0;i<l1&&j<l2;i++){
        if(s2[j]==s1[i]){
            ll[j]=i;
            j++;
        }
    }
    if(j<l2){
        puts("No");
        return 0;
    }
    for(i=l1-1,j=l2-1;i>=0&j>=0;i--){
        if(s2[j]==s1[i]){
            rr[j]=i;
            j-- ;
        }
    }
    for(i=0;i<l2;i++){
        qq[s2[i]-'a'].pb(data(ll[i],rr[i]));
    }
    for(i=0;i<l1;i++){
        int u=s1[i]-'a';
        while(now[u]<qq[u].size()&&qq[u][now[u]].y<i){
            now[u]++;
        }
        if(now[u]>=qq[u].size()||qq[u][now[u]].x>i){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}
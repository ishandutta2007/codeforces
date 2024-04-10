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
char s[5010];
int an[1000000],d[5010];
struct data{
    short x,y;
    int No;
    data(int _x=0,int _y=0,int _No=0){x=_x;y=_y;No=_No;}
    bool operator<(const data& b)const{
        return x>b.x||(x==b.x&&y<b.y);
    }
};
vector<data>ha;
bool compare(int x,int y){
    return x>y;
}
void insert(int x){
    while(x<5010){
        d[x]++;
        x+=x&-x;
    }
}
int query(int x){
    int res=0;
    while(x){
        res+=d[x];
        x-=x&-x;
    }
    return res;
}
vector<int>yo;
int mp(int x,int y){return (x<<13)|y;}
int main(){
    int i,j,k,n,q;
    gets(s);
    scanf("%d",&q);
    for(i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        x--;y--;
        ha.pb(data(x,y,i));
    }
    for(i=0;s[i];i++){
        for(j=1;j<=i&&s[i-j]==s[i+j];j++)yo.pb(mp(i-j,i+j));
        for(j=1;j<=i+1&&s[i-j+1]==s[i+j];j++)yo.pb(mp(i-j+1,i+j));
    }
    sort(ha.begin(),ha.end());
    sort(yo.begin(),yo.end(),compare);
    for(i=j=0;i<ha.size();i++){
        while(j<yo.size()&&(yo[j]>>13)>=ha[i].x){insert((yo[j]&8191)+1);j++;}
        an[ha[i].No]=query(ha[i].y+1)+ha[i].y-ha[i].x+1;
    }
    for(i=0;i<q;i++)printf("%d\n",an[i]);
    return 0;
}
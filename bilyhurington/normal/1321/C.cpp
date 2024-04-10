/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-01 21:43:00
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n;
struct node{
    char ch;
    int l,r;
}p[110];
char s[110];
bool cmp(int i){
    if(p[p[i].l].ch==p[i].ch-1) return 1;
    if(p[p[i].r].ch==p[i].ch-1) return 1;
    return 0;
}
void del(int i){
    p[p[i].l].r=p[i].r;
    p[p[i].r].l=p[i].l;
}
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) p[i].ch=s[i],p[i].l=i-1,p[i].r=i+1;
    p[0].r=1;
    for(int ti=1;ti<n;ti++){
        int maxp=0;
        for(int i=p[0].r;i!=n+1;i=p[i].r){
            if(cmp(i)&&p[i].ch>p[maxp].ch) maxp=i;
        }
        if(!maxp){printf("%d",ti-1);return 0;}
        del(maxp);
    }
    printf("%d",n-1);
    return 0;
}
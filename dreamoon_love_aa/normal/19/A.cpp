#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct data{
    char s[99];
    int point,gain,lose;
    bool operator<(data b)const{
        if(point>b.point)return 1;
        if(point<b.point)return 0;
        if(gain-lose>b.gain-b.lose)return 1;
        if(gain-lose<b.gain-b.lose)return 0;
        return gain>b.gain;
    }
}a[52];
struct Name{
    char s[99];
    bool operator<(Name b)const{return strcmp(s,b.s)<0;}
}an[50];
map<string,int>H;
main(){
    int n,m,i,j,x,y,px,py;
    char s1[99],s2[99];
    scanf("%d",&n);
    m=n*(n-1)/2;
    for(i=0;i<n;i++){
        scanf("%s",a[i].s);
        H[a[i].s]=i;
    }
    for(i=0;i<m;i++){
        scanf("%s%s",s1,s2);
        for(j=0;s1[j]!='-';j++);
        s1[j]=0;
        x=H[s1];
        y=H[s1+j+1];
        for(j=0;s2[j]!=':';j++);
        s2[j]=0;
        px=atoi(s2);
        py=atoi(s2+j+1);
        if(px>py)
            a[x].point+=3;
        else if(px<py)
            a[y].point+=3;
        else{
            a[x].point++;
            a[y].point++;
        }
        a[x].gain+=px;
        a[x].lose+=py;
        a[y].gain+=py;
        a[y].lose+=px;
    }
    sort(a,a+n);
    for(i=0;i<n/2;i++)strcpy(an[i].s,a[i].s);
    sort(an,an+n/2);
    for(i=0;i<n/2;i++)puts(an[i].s);
    n++;
}
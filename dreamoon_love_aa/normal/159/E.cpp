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
struct data{
    int x,y,No;
    bool operator<(const data& b)const{
        return x<b.x||(x==b.x&&y>b.y);
    }
}a[200000];
long long ma[200000];
int No[200000],st1,st2,len;
int main(){
    int i,j,n;
    long long an=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
        a[i].No=i+1;
    }
    sort(a,a+n);
    for(i=0;i<n;i+=j){
        long long now=0;
        for(j=0;i+j<n&&a[i].x==a[i+j].x;j++){
            now+=a[i+j].y;
            if(j){
                if(ma[j]&&now+ma[j]>an){
                    an=now+ma[j];
                    st1=i;
                    st2=No[j];
                    len=j*2+1;
                }
            }
            if(ma[j+1]&&now+ma[j+1]>an){
                an=now+ma[j+1];
                st1=i;
                st2=No[j+1];
                len=j*2+2;
            }
            if(ma[j+2]&&now+ma[j+2]>an){
                an=now+ma[j+2];
                st1=No[j+2];
                st2=i;
                len=j*2+3;
            }
        }
        now=0;
        for(j=0;i+j<n&&a[i].x==a[i+j].x;j++){
            now+=a[i+j].y;
            if(now>ma[j+1]){
                ma[j+1]=now;
                No[j+1]=i;
            }
        }
    }
    cout<<an<<endl;
    printf("%d\n",len);
    for(i=0;i<len;i++){
        if(i)putchar(' ');
        if(i&1)printf("%d",a[st2+i/2].No);
        else printf("%d",a[st1+i/2].No);
    }
    puts("");
    return 0;
}
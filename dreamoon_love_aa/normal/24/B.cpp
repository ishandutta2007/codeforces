#include<stdio.h>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
const int score[10]={25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
int person;
map<string,int>H;
int compare;
struct data{
    char s[99];
    int point,d[50];
    bool operator<(data b)const{
        if(compare){
            if(d[0]>b.d[0])return 1;
            if(d[0]<b.d[0])return 0;
            if(point>b.point)return 1;
            if(point<b.point)return 0;
            for(int i=1;i<50;i++){
                if(d[i]>b.d[i])return 1;
                if(d[i]<b.d[i])return 0;
            }
        }
        else{
            if(point>b.point)return 1;
            if(point<b.point)return 0;
            for(int i=0;i<50;i++){
                if(d[i]>b.d[i])return 1;
                if(d[i]<b.d[i])return 0;
            }
        }
        return 0;
    }
}a[1000];
main(){
    int n,i,x,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%s",a[person].s);
            if(H.count(a[person].s)==0){
                H[a[person].s]=person;
                x=person;
                person++;
            }
            else x=H[a[person].s];
            a[x].d[i]++;
            if(i<10)
                a[x].point+=score[i];
        }
    }
    sort(a,a+person);
    printf("%s\n",a[0].s);
    compare=1;
    sort(a,a+person);
    printf("%s\n",a[0].s);
}
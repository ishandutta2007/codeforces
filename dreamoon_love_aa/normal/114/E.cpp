#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<bitset>
#include<set>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#define pb push_back
using namespace std;
typedef unsigned int IU;
//bitset<300000000>haha;
int record[30]={332181,302990,293609,287908,283765,280218,278048,275655,274020,272111,270854,269117,268389,267056,266064,264739,264226,263745,262664,261462,261268,260763,259931,259477,258715,258403,258126,257244,256730,256241};
bool p[17320];
int pp[10000],pn;
//int d[30];
int f(int l,int r){
    int an=0,i,j;
    if(l<=2&&r>=2)an++;
    static bool haha[10000000];
    memset(haha,0,sizeof(haha));
    while(l%4!=1)l++;
    if(l==1)l=5;

    if(l>r)return an;
    for(i=0;i<pn;i++)
        for(j=max((l+pp[i]-1)/pp[i]*pp[i],pp[i]<<1);j<=r;j+=pp[i])haha[j-l]=1;
    for(i=0;i<=r-l;i+=4)
        if(!haha[i])an++;
    return an;
}
int main(){
    int i,j,k,l,r,an=0;
    for(i=3;i<17320;i+=2){
        if(!p[i]){
            pp[pn++]=i;
            for(j=i*i;j<17320;j+=i+i)p[j]=1;
        }
    }
    scanf("%d%d",&l,&r);
    for(i=0;i<30;i++){
        if(i*10000000>=l&&(i+1)*10000000-1<=r)an+=record[i];
        else{
            an+=f(max(i*10000000,l),min((i+1)*10000000-1,r));
        }
    }
    cout<<an<<endl;
    /*
    for(i=3;i<17320;i+=2)
        if(!haha[i])
            for(j=i*i;j<300000000;j+=i+i)haha[j]=1;
    for(i=5;i<300000000;i+=4)
        if(!haha[i])d[i/10000000]++;
    d[0]++;
    for(i=0;i<30;i++)printf("%d,",d[i]);
    */
    return 0;
}
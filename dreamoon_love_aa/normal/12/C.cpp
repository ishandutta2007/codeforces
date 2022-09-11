#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#define SIZE 110
using namespace std;
int a[SIZE],b[SIZE];
map<string,int>H;

main(){
    int n,m,i,j,an;
    char s[99];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    sort(a,a+n);
    while(m--){
        scanf("%s",s);
        if(!H.count(s))H[s]=1;
        else H[s]++;
    }
    map<string,int>::iterator it;
    for(m=0,it=H.begin();it!=H.end();it++)b[m++]=it->second;
    sort(b,b+m);
    an=0;
    for(i=m-1,j=0;i>=0;i--,j++)an+=b[i]*a[j];
    printf("%d ",an);
    an=0;
    for(i=m-1,j=n-1;i>=0;i--,j--)an+=b[i]*a[j];
    printf("%d\n",an);
}
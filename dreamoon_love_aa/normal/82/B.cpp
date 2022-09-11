#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 210
vector<int>d[SIZE];
struct data{
    int x;
    bool operator<(data b)const{
        if(d[x].size()<d[b.x].size())return 0;
        if(d[x].size()>d[b.x].size())return 1;
        int n=d[x].size(),i;
        for(i=0;i<n;i++){
            if(d[x][i]!=d[b.x][i])return d[x][i]<d[b.x][i];
        }
        return x<b.x;
    }
    bool equal(data &b){
        if(d[x].size()!=d[b.x].size())return 0;
        int i,n=d[x].size();
        for(i=0;i<n;i++)
            if(d[x][i]!=d[b.x][i])return 0;
        return 1;
    }
}a[SIZE];
main(){
    int n,m,k,i,j,x;
    scanf("%d",&n);
    if(n==2){
        scanf("%d",&k);
        scanf("%d",&x);
        printf("1 %d\n",x);
        k--;
        printf("%d",k);
        while(k--){
            scanf("%d",&x);
            printf(" %d",x);
        }
        puts("");
    }
    else{
        m=n*(n-1)/2;
        for(i=0;i<m;i++){
            scanf("%d",&k);
            while(k--){
                scanf("%d",&x);
                d[x].push_back(i);
            }
        }
        m=0;
        for(i=0;i<SIZE;i++)
            if(d[i].size())a[m++].x=i;
        sort(a,a+m);
        for(i=0;i<m&&d[a[i].x].size();i=j){
            for(j=i+1;j<m&&a[i].equal(a[j]);j++);
            printf("%d",j-i);
            for(k=i;k<j;k++)printf(" %d",a[k].x);
            puts("");
        }
    }
}
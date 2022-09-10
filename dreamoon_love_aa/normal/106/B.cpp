#include<stdio.h>
struct data{
    int d[3],cost;
    void scan(){scanf("%d%d%d%d",&d[0],&d[1],&d[2],&cost);}
    bool operator<(data b)const{return d[0]<b.d[0]&&d[1]<b.d[1]&&d[2]<b.d[2];}
}a[100];
bool used[100];
main(){
    int n,mi=1000000,i,j,an;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        a[i].scan();
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)continue;
            if(a[i]<a[j])used[i]=1;
        }
    }
    for(i=0;i<n;i++){
        if(!used[i]&&a[i].cost<mi){
            mi=a[i].cost;
            an=i+1;
        }
    }
    printf("%d\n",an);
}
#include<stdio.h>
bool finish(int d[4]){
    int i;
    for(i=0;i<4;i++)
        if(d[i]!=1)return 0;
    return 1;
}
int tail(int d[4],int &one){
    int i,an=0;
    one=0;
    for(i=0;i<4;i++){
        an+=(1<<i)*(d[i]&1);
        if(d[i]&1)one++;
    }
    return an;
}
int seq[4]={3,6,12,9};
main(){
    int d[4],i,j,res,one;
    for(i=0;i<4;i++)scanf("%d",&d[i]);
    while(!finish(d)){
        res=tail(d,one);
        for(i=0;i<4;i++){
            if((res&seq[i])==0){
                printf("/%d\n",i+1);
                d[i]/=2;
                d[(i+1)%4]/=2;
                break;
            }
        }
        if(i==4){
            if(one==2){
                printf("+1\n");
                d[0]++;
                d[1]++;
            }
            else{
                for(i=0;i<4;i++){
                    if((res&seq[i])==seq[i]&&(d[i]+d[(i+1)%4])!=2){
                        d[i]++;
                        d[(i+1)%4]++;
                        printf("+%d\n",i+1);
                        break;
                    }
                }
                if(i==4){
                    for(i=0;d[i]==1;i++);
                    printf("+%d\n",i+1);
                    d[i]++;
                    d[(i+1)%4]++;
                }
            }
        }
    }
}
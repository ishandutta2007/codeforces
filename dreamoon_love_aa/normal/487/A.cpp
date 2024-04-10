#include<cstdio>
int min(int x,int y){return x<y?x:y;}
int max(int x,int y){return x>y?x:y;}
int main(){
    int HY,AY,DY,HM,AM,DM,h,a,d;
    scanf("%d%d%d",&HY,&AY,&DY);
    scanf("%d%d%d",&HM,&AM,&DM);
    scanf("%d%d%d",&h,&a,&d);
    int an=2e9;
    for(int dd=0;dd<=110;dd++)
        for(int da=0;da<=210;da++){
            int ll=0,rr=1e5;
            if(AY+da<=DM)continue;
            while(ll<rr){
                int mm=(ll+rr)/2;
                int need=1e9;
                if(max(0,AM-(DY+dd))!=0)need=(HY+mm-1)/(AM-(DY+dd));
                if((long long)need*max(0,(AY+da)-DM)>=HM)rr=mm;
                else ll=mm+1;
            }
            an=min(an,dd*d+da*a+h*ll);
        }
    printf("%d\n",an);
    return 0;
}
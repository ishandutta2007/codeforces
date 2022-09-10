#include<cstdio>
#define LL long long
int pp[111111],d[111111],dn;
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        puts("YES\n1");
    }
    else if(n==2){
        puts("YES\n1\n2");
    }
    else if(n==3){
        puts("YES\n1\n2\n3");
    }
    else if(n==4){
        puts("YES\n1\n3\n2\n4");
    }
    else{
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                puts("NO");
                return 0;
            }
        }
        int root=2;
        while(1){
            int now=1;
            bool err=0;
            for(int i=1;i<n-1;i++){
                now=((LL)now*root)%n;
                if(now==1){
                    err=1;
                    break;
                }
            }
            if(!err)break;
            root++;
        }
        pp[0]=1;
        for(int i=1;i<=n;i++)pp[i]=(LL)pp[i-1]*root%n;
        puts("YES");
        int ll=0,rr=n-2;
        while(ll<=rr){
            d[dn++]=ll++;
            if(ll<=rr)d[dn++]=rr--;
        }
        printf("1\n");
        for(int i=1;i<dn;i++){
            printf("%d\n",pp[(d[i]-d[i-1]+n-1)%(n-1)]);
        }
        printf("%d\n",n);
    }
}
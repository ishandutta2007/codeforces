#include<stdio.h>
int a[100010],b[100010],n,an[100010],num;
int To(int x){return ((x%n)+n)%n;}
main(){
    int i,j,now;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=0;i<n;i=j+1){
        now=0;
        for(j=i;j<i+n-1;j++){
            if(now+a[To(j)]-b[To(j)]<0)break;
            else now+=a[To(j)]-b[To(j)];
        }
        if(j==i+n-1){
            now=j=0;
            do{
                if(!now)an[To(i+j)]=1;
                now+=a[To(i+j)]-b[To(i+j)];
                j++;
            }while(j<n);
            break;
        }
    }
    for(i=n-1;i>=0;i=j-1){
        now=0;
        for(j=i;j>i-n+1;j--){
            if(now+a[To(j)]-b[To(j-1)]<0)break;
            else now+=a[To(j)]-b[To(j-1)];
        }
        if(j==i-n+1){
            now=j=0;
            do{
                if(!now)an[To(i-j)]=1;
                now+=a[To(i-j)]-b[To(i-j-1)];
                j++;
            }while(j<n);
            break;
        }
    }
    for(i=0;i<n;i++)
        if(an[i])num++;
    printf("%d\n",num);
    num=0;
    for(i=0;i<n;i++){
        if(an[i]){
            if(num)putchar(' ');
            else num++;
            printf("%d",i+1);
        }
    }
    puts("");
}
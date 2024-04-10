#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int p=0,l=1,r=1;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1])goto fail;
        switch(p){
            case 0:
                if(a[i]<a[i-1]){l=i;p=1;r=n;}
                break;
            case 1:
                if(a[i]>a[i-1]){p=2;r=i;}
                break;
            case 2:
                if(a[i]<a[i-1])goto fail;
                break;
        }
    }
    if(((l>1)&&(a[l-2]>=a[r-1]))||((r<n)&&(a[r]<=a[l-1])))goto fail;
    printf("yes\n%d %d",l,r);
    return 0;
    fail: printf("no");
}
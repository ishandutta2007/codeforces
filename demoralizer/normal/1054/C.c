#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int l[n],r[n],t[n];
    for(int i=0;i<n;i++)
        scanf("%d",&l[i]);
    for(int i=0;i<n;i++){
        scanf("%d",&r[i]);
        t[i]=n-l[i]-r[i];
        if(t[i]<1){goto fail;}
    }
    for(int i=0;i<n;i++){
        int a=0,b=0;
        for(int j=0;j<i;j++)
            if(t[j]>t[i])a++;
        for(int j=i+1;j<n;j++)
            if(t[j]>t[i])b++;
        if((a!=l[i])||(b!=r[i])){goto fail;}
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
        printf("%d ",t[i]);
    return 0;
    fail: printf("NO");
}
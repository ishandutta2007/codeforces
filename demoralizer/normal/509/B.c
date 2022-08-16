#include<stdio.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    scanf("%d",&a[0]);
    int max=a[0],min=a[0];
    for(int i=1;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]>max)max=a[i];
        if(a[i]<min)min=a[i];
    }
    if(k<(max-min)){printf("NO");return 0;}
    printf("YES\n");
    for(int i=0;i<n;i++){
        for(int j=1;j<=a[i];j++){
            int t=j-min;
            if(t<1)t=1;
            printf("%d ",t);
        }
        printf("\n");
    }
}
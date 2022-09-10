#include<stdio.h>
#include<vector>
using namespace std;
int a[200001];
vector<int>an;
main(){
    int i,sum=0,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int first=1;
    for(i=1;i<=n;i++){
        if(sum%a[i]==0&&sum/a[i]==n){
            if(!first)putchar(' ');
            else first=0;
            an.push_back(i);
        }
    }
    printf("%d\n",an.size());
    for(i=0;i<an.size();i++){
        if(i)putchar(' ');
        printf("%d",an[i]);
    }
    puts("");
}
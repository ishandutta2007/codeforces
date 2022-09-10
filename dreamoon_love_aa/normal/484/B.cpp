#include<cstdio>
const int MAX = 2000000;
int d[MAX+1];
int max(int x,int y){return x>y?x:y;}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        d[x]=x;
    }
    for(int i=2;i<=MAX;i++){
        d[i]=max(d[i],d[i-1]);
    }
    int an=0;
    for(int i=2;i<=MAX;i++){
        if(d[i]==i){
            for(int j=i+i;j<=MAX;j+=i)an=max(an,d[j-1]%i);
        }
    }
    printf("%d\n",an);
    return 0;
}
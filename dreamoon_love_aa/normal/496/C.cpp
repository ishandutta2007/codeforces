#include<cstdio>
#include<cstring>
const int SIZE = 1010;
char s[SIZE][SIZE];
bool ac[SIZE];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%s",s[i]);
    if(n==1){
        puts("0");
        return 0;
    }
    int an=0;
    for(int i=0;i<m;i++){
        bool wa=0;
        for(int j=0;j+1<n;j++){
            if(s[j][i]>s[j+1][i]&&!ac[j]){
                wa=1;
                break;
            }
        }
        if(wa)an++;
        else{
            for(int j=0;j+1<n;j++){
                if(s[j][i]<s[j+1][i])ac[j]=1;
            }
        }
    }
    printf("%d\n",an);
    return 0;
}
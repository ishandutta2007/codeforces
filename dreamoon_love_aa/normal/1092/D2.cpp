#include<cstdio>
int m;
int a[200000];
int cnt[200000];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        while(m&&a[m-1]<x){
            if(cnt[m-1]&1){
                puts("NO");
                return 0;
            }
            m--;
        }
        if(!m||a[m-1]!=x){
            cnt[m]=1;
            a[m++]=x;
        }
        else{
            cnt[m-1]++;
        }
    }
    for(int i=1;i<m;i++){
        if(cnt[i]&1){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
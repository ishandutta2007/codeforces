#include<bits/stdc++.h>
using namespace std;
void solve(int n,int m){
    if (n == 1){
        printf("%d ",m);
        return ;
    }else if (n == 2){
        printf("%d %d ",m,2*m);
        return;
    }else if (n == 3){
        printf("%d %d %d ",m,m,3*m);
        return;
    }else if (n == 4){
        printf("%d %d %d %d ",m,m,2*m,4*m);
        return;
    }else if (n == 5){
        printf("%d %d %d %d %d ",m,m,m,2*m,4*m);
        return;
    }
    int N = (n+1) >>1;
    for (int i=0;i<N;i++){
        printf("%d ",m);
    }
    solve(n/2,m*2);
}
int main(){
    int n;
    cin>>n;
    solve(n,1);
    return 0;
}
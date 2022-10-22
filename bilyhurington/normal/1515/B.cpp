/*
 * @Author: BilyHurington
 * @Date: 2021-05-02 22:36:28
 * @LastEditors: BilyHurington
 * @LastEditTime: 2021-05-02 22:47:06
 */
#include<bits/stdc++.h>
#ifdef LOCAL_TEST
#include<ctime>
#endif
using namespace std;
int T,n;
bool is_sq(int n){
    int S=sqrt(n);
    if(S*S==n) return 1;
    else return 0;
}
int main(){
    #ifdef LOCAL_TEST
    clock_t start=clock();
    #endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        if((n%2==0&&is_sq(n/2))||(n%4==0&&is_sq(n/4))) puts("YES");
        else puts("NO");
    }
    #ifdef LOCAL_TEST
    clock_t end=clock();cout<<endl;
    cout<<"The program costs "<<(double)(end-start)/CLOCKS_PER_SEC<<" seconds"<< endl;
    puts("");system("pause");
    #endif
    return 0;
}
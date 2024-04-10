#include<bits/stdc++.h>
using namespace std;
void workWrong(int n){
    if (n<6){
        cout<<-1<<endl;
    }else{
        printf("1 2\n2 3\n2 4\n");
        for (int i=5;i<=n;i++){
            printf("%d 4\n",i);
        }
    }
}
void workTrue(int n){
    for (int i=2;i<=n;i++){
        printf("%d 1\n",i);
    }
}
int main(){
    int n;
    cin>>n;
    workWrong(n);
    workTrue(n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3+100;
char a[maxn];
int n;
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        a[i]='o';
    }
    a[n+1]='\0';
    int f1=1,f2=1;
    while (f1<=n){
        a[f1] ='O';
        int temp = f1+f2;
        f1 = f2;
        f2 = temp;
    }
    cout<<a+1<<endl;
    return 0;
}
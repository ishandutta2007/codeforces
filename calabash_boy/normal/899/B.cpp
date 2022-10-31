#include<bits/stdc++.h>
using namespace std;
const int maxn = 25;
int a[maxn];
int bas1[1000] = {31,28,31,30,31,30,31,31,30,31,30,31};
int bas2[1000] = {31,29,31,30,31,30,31,31,30,31,30,31};
int n;
void init(){
    for (int i=1;i<=2;i++){
        for (int j =0;j<12;j++){
            bas1[i*12+j] = bas1[j];
        }
    }
    for (int i=0;i<12;i++){
        bas1[36+i] = bas2[i];
    }
    for (int i=1;i<=2;i++){
        for (int j=0;j<48;j++){
            bas1[48*i+j] = bas1[j];
        }
    }
}
void input(){
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
}
void solve(){
    for (int i=0;i<=48*3-n;i++){
        bool flag = true;
        for (int j=0;j<n;j++){
            if (bas1[i+j]!=a[j]){
                flag = false;
                break;
            }
        }
        if (flag){
            cout<<"Yes"<<endl;
            return ;
        }
    }
    cout<<"No"<<endl;
}
int main(){
    init();
    input();
    solve();
    return 0;
}
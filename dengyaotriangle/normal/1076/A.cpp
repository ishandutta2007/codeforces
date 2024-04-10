#include<bits/stdc++.h>

using namespace std;

const int maxn=2000005;

int n;
char x[maxn];

int main(){
    cin>>n>>(x+1);
    int dl=n;
    for(int i=1;i<n;i++){
        if(x[i]>x[i+1]){
            dl=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(i!=dl)cout<<x[i];
    }
    return 0;
}
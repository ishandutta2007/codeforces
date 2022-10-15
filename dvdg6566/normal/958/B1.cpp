#include<bits/stdc++.h>
using namespace std;

int N,a,b;
int mem[10010];
int main(){
    cin>>N;
    for (int i=1;i<N;++i){
        cin>>a>>b;++mem[a];++mem[b];
    }
    a=0;
    for (int i=1;i<=N;++i)if(mem[i] == 1)++a;
    cout<<a;
}
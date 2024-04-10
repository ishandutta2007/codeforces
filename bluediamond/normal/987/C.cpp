#include <bits/stdc++.h>

using namespace std;

const int N=3000;
int n,v[N+5],cost[N+5];
int bst[N+5],bst2[N+5];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>cost[i];
    }
    for(int i=1;i<=n;i++){
        bst[i]=(1<<30);
        for(int j=1;j<i;j++){
            if(v[j]<v[i]){
                bst[i]=min(bst[i],cost[j]+cost[i]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        bst2[i]=(1<<30);
        for(int j=1;j<i;j++){
            if(v[j]<v[i]){
                bst2[i]=min(bst2[i],bst[j]+cost[i]);
            }
        }
    }
    int sol=(1<<30);
    for(int i=1;i<=n;i++){
        sol=min(sol,bst2[i]);
    }
    if(sol==(1<<30)){
        cout<<"-1\n";
    }
    else{
        cout<<sol<<"\n";
    }
    return 0;
}
/**

**/
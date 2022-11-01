#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int ans[200005];

void calc(int cur){
    int rt=1;
    while(rt*rt<n)rt++;
    for(int i=1;i<rt;i++){
        if(a[cur]<a[(cur-1)/i]){
            ans[i]++;
            ans[i+1]--;
        }
    }
    for(int i=rt,fa,j;i<n;i=j){
        fa=(cur-1)/i;
        if(fa)j=(cur-1)/fa+1;
        else j=n;
        if(a[cur]<a[(cur-1)/i]){
            ans[i]++;
            ans[j]--;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
        calc(i);
    }
    for(int i=1;i<n;i++){
        ans[i]+=ans[i-1];
        cout<<ans[i]<<' ';
    }

    return 0;
}
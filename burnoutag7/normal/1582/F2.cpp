#include<bits/stdc++.h>
using namespace std;

int n,a[1000005],r[1<<13];
vector<int> v[1<<13];
bool hav[1<<13];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    hav[0]=1;
    r[0]=(1<<13)-1;
    for(int i=1;i<1<<13;i++){
        v[i].emplace_back(0);
        r[i]=(1<<13)-1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int x:v[a[i]]){
            int y=x^a[i];
            hav[y]=1;
            while(r[y]>a[i]){
                v[r[y]--].emplace_back(y);
            }
        }
        v[a[i]].clear();
    }
    cout<<accumulate(hav,hav+(1<<13),0)<<'\n';
    for(int i=0;i<1<<13;i++)if(hav[i])cout<<i<<' ';

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N=100;
int n,k,v[N+5];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n/2;i++){
        cin>>v[i];
    }
    sort(v+1,v+n/2+1);
    int bst=(1<<30);
    for(int p=0;p<2;p++){
        int poz=0,cost=0;
        if(p==0)
            poz=2;
        else
            poz=1;
        for(int i=1;i<=n/2;i++){
            if(v[i]!=poz){
                cost+=abs(v[i]-poz);
            }
            poz+=2;
        }
        bst=min(bst,cost);
    }
    cout<<bst;
    return 0;
}
/**




**/
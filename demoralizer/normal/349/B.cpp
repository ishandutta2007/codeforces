#include <bits/stdc++.h>
using namespace std;
#define pb push_back
int main(){
    ios_base::sync_with_stdio(false);
    int v,m=-1,j=-1,k;
    cin>>v;
    int a[10];
    for(int i=1;i<10;i++){cin>>a[i];if(m==-1||a[i]<m){m=a[i];k=i;}}
    m=v/a[k];if(m==0){cout<< (-1);return 0;}
    v=v%a[k];
    for(int i=0;i<m;i++){
        if(j!=k)
        for(j=9;j>k;j--)
            if(a[j]-a[k]<=v){v-=a[j]-a[k];break;}
        cout<<j;
    }
}
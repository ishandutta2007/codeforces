#include <bits/stdc++.h>

using namespace std;

bool is(int x){
    int nr=0;
    int cate=0;
    while(x%2==0){
        x/=2;
        cate++;
    }
    if(cate>0)
        nr++;
    int d=3;
    while(d*d<=x){
        cate=0;
        while(x%d==0){
            x/=d;
            cate++;
        }
        if(cate>0)
            nr++;
        if(nr>2)
            return 0;
        d+=2;
    }
    if(x>1)
        nr++;
    if(nr==2)
        return 1;
    return 0;
}
int n,s=0;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        if(is(i)==1)
            s++;
    }
    cout<<s;
    return 0;
}
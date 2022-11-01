#include<bits/stdc++.h>
using namespace std;

int n,q,fail;
bool g[2][100005];

void rmv(int h,int l){
    if(l>0)if(g[h^1][l-1])fail--;
    if(l+1<n)if(g[h^1][l+1])fail--;
    if(g[h^1][l])fail--;
    g[h][l]^=1;
}

void add(int h,int l){
    if(l>0)if(g[h^1][l-1])fail++;
    if(l+1<n)if(g[h^1][l+1])fail++;
    if(g[h^1][l])fail++;
    g[h][l]^=1;
}

void func(int h,int l){
    if(g[h][l]){
        rmv(h,l);
    }else{
        add(h,l);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    while(q--){
        int r,c;
        cin>>r>>c;
        r--;c--;
        func(r,c);
        if(!g[1][n-1]&&fail==0){
            cout<<"yEs"<<endl;
        }else{
            cout<<"nO"<<endl;
        }
    }

    return 0;
}
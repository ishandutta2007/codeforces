#include<bits/stdc++.h>
using namespace std;

int T,n;
int a[1005];
bool u[1005];

int find_mex(){
    for(int i=0;i<=n;i++)u[i]=0;
    for(int i=1;i<=n;i++)u[a[i]]=1;
    for(int i=0;i<=n;i++)if(!u[i])return i;
}

int find_ele(int x){
    for(int i=1;i<=n;i++)if(x==a[i])return i;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        vector<int> v;
        int mex;
        while((mex=find_mex())!=n){
            a[mex+1]=mex;
            v.push_back(mex+1);
        }
        for(int i=1;i<=n;i++){
            while((mex=find_mex())!=i-1&&a[i]!=i-1){
                int pos=find_ele(i-1);
                a[pos]=mex;
                v.push_back(pos);
            }
            if(a[i]!=i-1){
                a[i]=i-1;
                v.push_back(i);
            }
        }
        for(int i=1;i<=n;i++){
            assert(a[i]==i-1);
        }
        cout<<v.size()<<'\n';
        for(int &x:v)cout<<x<<' ';
        cout<<'\n';
    }

    return 0;
}
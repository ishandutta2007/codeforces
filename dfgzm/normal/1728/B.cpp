#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int i,j,k,n,m,is[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        int S=-1,id=1;
        cin>>n;
        for(i=1;i<=n;i++)is[i]=1;
        is[1]=is[n-2]=is[n]=0;
        if(n==4){cout<<"2 1 3 4"<<endl;continue;}
        int Num=0;
        vector<int>V;
        for(i=1;i<=n;i++)if(is[i])V.push_back(i);
        if(V.size()%2==1){
            cout<<V[0]<<' '<<V[V.size()-1]<<' ';
            for(i=V.size()-2;i>=1;i--)cout<<V[i]<<' ';
        }else for(i=V.size()-1;i>=0;i--)cout<<V[i]<<' ';
        for(i=1;i<=n;i++)if(!is[i])cout<<i<<' ';cout<<endl;
    }
}
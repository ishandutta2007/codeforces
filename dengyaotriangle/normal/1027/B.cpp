#include<bits/stdc++.h>

using namespace std;

long long n;
int q;
long long x,y;

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>q;
    
    while(q--){
        cin>>x>>y;
        if(n%2==1){
            long long g=(x-1)*n+y;
            if(g%2){
                cout<<(g+1)/2<<'\n';
            }else{
                cout<<g/2+(n*n+1)/2<<'\n';
            }
        }else{
            long long a=(x-1)*n/2;
            long long b=(y)/2;
            bool g=(x+y)%2==0;
            if(!(g^(bool)(x%2))) b++;
            if(g)cout<<a+b<<'\n';
            else cout<<(n*n+1)/2+a+b<<'\n';
        }
        
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()

ll A,B,C,T;

int main(){
    cin>>T;
    while(T--){
        cin>>A>>B;
        if(B==1){
            cout<<"NO\n";
        }else{
            cout<<"YES\n";
            cout<<A<<' '<<A*B*2<<' '<<A*B*2+A<<'\n';
        }
    }
}
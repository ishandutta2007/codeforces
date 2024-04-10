#include <bits/stdc++.h>
using namespace std;
char x;
long long n;
bool t;
int kol[20000];
int main(){
    cin>>n;
    for (int i=1;i<=4;++i){
        for (int j=1;j<=4;++j){
            cin>>x;
            if (x!='.'){
                ++kol[x];
                if (kol[x]>n*2){
                    t=true;
                }
            }
        }
    }
    if (t==true) cout<<"NO";
    else cout<<"YES";
}
#include <bits/stdc++.h>
using namespace std;
int n,x;
int one,two,three;
bool t;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x;
        //cout<<one<<" "<<two<<" "<<three<<endl;
        if (x==25) ++one;
        else if (x==50){
            if (one==0) t=true;
            else --one;
            ++two;
        } else {
            if (one>0 && two>=1){
                ++three;
                --one;
                two--;
            } else if (one>=3){
                one-=3;
                ++three;
            } else t=true;
        }
    }
    if (t==false) cout<<"YES";
    else cout<<"NO";
}
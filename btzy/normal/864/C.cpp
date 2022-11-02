#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,f,k;
    cin>>a>>b>>f>>k;
    int p=b-f;
    if(p<0){cout<<-1<<endl;return 0;}
    int refct=0;
    bool rev=false;
    while(k-->0){
        int l;
        if(!rev){
            if(k==0)l=(a-f);
            else l=(a-f)<<1;
        }
        else{
            if(k==0)l=f;
            else l=f<<1;
        }
        if(p<l){
            //cout<<k<<endl;
            ++refct;
            p=b;
        }
        p-=l;
        rev=!rev;
        if(p<0){cout<<-1<<endl;return 0;}
    }
    cout<<refct<<endl;
}
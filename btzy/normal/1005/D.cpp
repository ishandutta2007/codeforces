#include <iostream>
#include <algorithm>
#include <cstdint>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int bests[3]={0,INT_MIN,INT_MIN};
    char ch;
    int mod=0;
    int val;
    while(cin>>ch){
        int num=ch-'0';
        mod+=num;
        mod%=3;
        val=0;
        for(int i=0;i<3;++i){
            val=max(val,bests[i]+(i==mod));
        }
        bests[mod]=max(bests[mod],val);
    }
    cout<<val<<'\n';
}
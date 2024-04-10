#include <iostream>
#include <set>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;
unsigned n;
unsigned arr[101]={0};
unsigned a2[100]={0};
unsigned a3[100];
unsigned a2_ct=0;
bool dp[101][101][51]={false};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(unsigned i=0;i<n;++i){
        unsigned x;
        cin>>x;
        ++arr[x];
    }
    for(unsigned i=0;i<=100;++i){
        if(arr[i]>0){
            a2[a2_ct]=arr[i];
            a3[a2_ct]=i;
            ++a2_ct;
        }
    }
    if(a2_ct==2&&a2[0]==a2[1]){
        cout<<"YES"<<endl<<a3[0]<<' '<<a3[1]<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
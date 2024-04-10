#include<bits/stdc++.h>
using namespace std;

int n;
int cur,ofs;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(n--){
        char c;
        cin>>c;
        if(c=='+'){
            cur++;
        }else{
            cur--;
        }
        if(cur<ofs)ofs=cur;
    }
    cout<<cur-ofs<<endl;

    return 0;
}
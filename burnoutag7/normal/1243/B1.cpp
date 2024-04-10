#include<bits/stdc++.h>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        map<char,int> ms,mt;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                ms[s[i]]++;
                mt[t[i]]++;
                cnt++;
            }
        }
        if(cnt!=2||ms.size()!=1||mt.size()!=1){
            cout<<"nO"<<endl;
        }else{
            cout<<"yEs"<<endl;
        }
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tc;
    cin>>tc;
    for(int ct=0;ct<tc;++ct){
        string str;
        cin>>str;
        int changes=0;
        for(size_t i=0;i!=str.size();++i){
            if((i>0&&str[i]==str[i-1])||(i>1&&str[i]==str[i-2])){
                str[i]='\0';
                ++changes;
            }
        }
        cout<<changes<<'\n';
    }
}